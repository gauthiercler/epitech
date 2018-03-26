module CodeGen.Instructions.Instructions where

import LLVM.AST

import Debug.Trace
import Control.Monad.State

import CodeGen.Instructions.References
import CodeGen.State
import CodeGen.Block


generateIdentifier :: CodeGen Word
generateIdentifier = do
    count <- gets count
    let newIdentifier = count + 1
    modify $ \lambda ->
        lambda {count = newIdentifier}
    return $ fromIntegral newIdentifier

instruction :: Instruction -> CodeGen Operand
--instruction ins | trace ("myfun " ++ show ins) False = undefined
instruction ins = do
    id <- generateIdentifier
    let ref = UnName id
    block <- getActiveBlock
    let stack' = stack block
    editBlock (block {stack = (ref := ins) : stack'})
    return $ localReference ref

getTerminator :: Named Terminator -> CodeGen (Named Terminator)
getTerminator term = do
  block <- getActiveBlock
  editBlock (block {terminator = Just term})
  return term

assignVariable :: String -> Operand -> CodeGen ()
assignVariable name value = do
    symtab <- gets symbolTable
    modify $ \lamdbda ->
        lamdbda {symbolTable = [(name, value)] ++ symtab}

getVariable :: String -> CodeGen Operand
getVariable name = do
    symtab <- gets symbolTable
    case lookup name symtab of
        Just elem -> return elem
        Nothing -> error $ "Local variable with identifier " ++ show name ++ " is not in scope"