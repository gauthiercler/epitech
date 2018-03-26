{-# LANGUAGE OverloadedStrings #-}

module CodeGen.Emitter where

import LLVM.AST
import LLVM.AST.AddrSpace

import qualified Data.ByteString.Char8 as B

import Control.Monad.Trans.Except
import Control.Monad
import Control.Monad.State

import Data.Map as Map

import KaleidoscopeParser.Syntax as S
import CodeGen.State
import CodeGen.Instructions.Memory
import CodeGen.Instructions.ControlFlow
import CodeGen.Instructions.References
import CodeGen.Module
import CodeGen.Block
import CodeGen.Generation
import CodeGen.Instructions.Instructions
import CodeGen.Instructions.Arithmetic as A

import qualified LLVM.AST.Constant as C
import qualified LLVM.AST.Float as F
import qualified LLVM.AST as AST
import LLVM.Context
import LLVM.Module
import LLVM.AST.Type


operators = fromList [
        ("+", A.add),
        ("-", A.sub),
        ("*", A.mul),
        ("/", A.div)
    ]

formatCallArgs :: [Expr] -> [AST.Type]
formatCallArgs = Prelude.map (\e -> i64)

gen :: Expr -> CodeGen Operand
gen (CallExpr function args) = do
    args' <- mapM gen args
    let fnT = AST.PointerType { AST.pointerReferent = AST.FunctionType { AST.resultType = i64, AST.argumentTypes = formatCallArgs args, AST.isVarArg = False} , AST.pointerAddrSpace = AddrSpace 0 }
    let oper = externReference fnT (mkName function)
    call oper args'
gen (Var var) = getVariable var >>= load
gen (Float float) = return $ constantReference $ C.Float (F.Double float)
gen (Number int) = return $ constantReference C.Int { C.integerValue = int, C.integerBits = 64 }
gen (BinOp operator leftTerm rightTerm) =
    case Map.lookup operator operators of
        Nothing -> error $ "Operator " ++ operator ++ " not handled"
        Just function -> do
            left <- gen leftTerm
            right <- gen rightTerm
            function left right
gen expr = error $ "pattern" ++ show expr


typeConverter :: S.Type -> AST.Type
typeConverter type' =
    case type' of
        S.Int -> i64
        S.Double -> double

formatArgs :: [Expr] -> [(AST.Type, AST.Name)]
formatArgs = Prelude.map (\e ->
            let (VarType type' name) = e
            in (typeConverter type', mkName name)
        )

startCodeGeneration :: Expr -> LLVM ()
startCodeGeneration (Def (Prototype name args retType) expr) =
    let retType' = typeConverter retType
    in define retType' name fnargs blocks
    where
        fnargs = formatArgs args
        blocks = createBlocks $ execCodeGen $ do
            entry <- addBlock entryBlockName
            setBlock entry
            forM_ args $ \a -> do
                let (VarType type' name') = a
                var <- alloca $ typeConverter type'
--                store var (localReference (mkName name'))
                assignVariable name' var
            gen expr >>= ret

startCodeGeneration (Extern (Prototype name args retType)) =
  let retType' = typeConverter retType
  in extern retType' name fnargs
  where fnargs = formatArgs args

startCodeGeneration exp =
  define i64 "main" [] blocks
  where
    blocks = createBlocks $ execCodeGen $ do
      entry <- addBlock entryBlockName
      setBlock entry
      gen exp >>= ret

runLLVM :: AST.Module -> LLVM a -> AST.Module
runLLVM mod (LLVM m) = execState m mod

codegen :: AST.Module -> [Expr] -> IO AST.Module
codegen mod fns = withContext $ \context ->
  withModuleFromAST context newast $ \m -> do
    llstr <- moduleLLVMAssembly m
    B.putStrLn llstr
    return newast
  where
    modn = mapM startCodeGeneration fns
    newast = runLLVM mod modn