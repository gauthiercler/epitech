module CodeGen.Instructions.ControlFlow where

import LLVM.AST

import CodeGen.State
import CodeGen.Instructions.Instructions

{- Cause control flow to transfer to a different basic block in the current function
    Br args:
        dest :: Name
        metadata' :: InstructionMetadata
-}
br :: Name -> CodeGen (Named Terminator)
br value = getTerminator $ Do $ Br value []

{- Cause control flow to transfer to a different basic block in the current function. Endpoint is defined by evaluated condition
    Cbr args:
        condition :: Operand
        trueDest :: Name
        falseDest :: Name
        metadata' :: InstructionMetadata
-}
cbr :: Operand -> Name -> Name -> CodeGen (Named Terminator)
cbr condition trueEndpoint falseEndpoint = getTerminator $ Do $ CondBr condition trueEndpoint falseEndpoint []

{- Return control flow (and maybe value) from a function back to the caller
    Ret args:
        returnOperand :: Maybe Operand
        metadata' :: InstructionMetadata
-}
ret :: Operand -> CodeGen (Named Terminator)
ret value = getTerminator $ Do $ Ret (Just value) []