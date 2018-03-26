module CodeGen.Instructions.Memory where

import CodeGen.State
import CodeGen.Instructions.Instructions

import Debug.Trace

import LLVM.AST
import LLVM.AST.CallingConvention
import LLVM.AST.Attribute

toArgs :: [Operand] -> [(Operand, [ParameterAttribute])]
toArgs = map (\x -> (x, []))

{- function call with given arguments
    Call args:
        tailCallKind :: Maybe TailCallKind
        callingConvention :: CallingConvention
        returnAttributes :: [ParameterAttribute]
        function :: CallableOperand
        arguments :: [(Operand, [ParameterAttribute])]
        functionAttributes :: [Either GroupID FunctionAttribute]
        metadata :: InstructionMetadata
-}
call :: Operand -> [Operand] -> CodeGen Operand
call function args = instruction $ Call Nothing C [] (Right function) (toArgs args) [] []

{- create a pointer to a stack allocated uninitialized value of the given type
    Alloca args:
        allocatedType :: Type
        numElements :: Maybe Operand
        alignment :: Word32
        metadata :: InstructionMetadata
-}
alloca :: Type -> CodeGen Operand
alloca type' = instruction $ Alloca type' Nothing 0 []

{- Write in memory
    Store args:
        volatile :: Bool
        address :: Operand
        value :: Operand
        maybeAtomicity :: Maybe Atomicity
        alignment :: Word32
        metadata :: InstructionMetadata
-}
store :: Operand -> Operand -> CodeGen Operand
--store ptr value | trace ("myfun " ++ show ptr ++ " | " ++ show value) False = undefined
store ptr value = instruction $ Store False ptr value Nothing 0 []

{- Read from memory
    Load args:
        volatile :: Bool
        address :: Operand
        maybeAtomicity :: Maybe Atomicity
        alignment :: Word32
        metadata :: InstructionMetadata
-}
load :: Operand -> CodeGen Operand
load ptr = instruction $ Load False ptr Nothing 0 []