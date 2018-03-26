module CodeGen.Instructions.Arithmetic where

import LLVM.AST

import CodeGen.State
import CodeGen.Instructions.Instructions

{- Basic arithmetic operations
    Args:
        fastMathFlags :: FastMathFlags
        operand0 :: Operand
        operand1 :: Operand
        metadata :: InstructionMetadata
-}

add :: Operand -> Operand -> CodeGen Operand
add a b = instruction $ Add False False a b []

sub :: Operand -> Operand -> CodeGen Operand
sub a b = instruction $ Sub False False a b []

mul :: Operand -> Operand -> CodeGen Operand
mul a b = instruction $ Mul False False a b []

div :: Operand -> Operand -> CodeGen Operand
div a b = instruction $ FDiv NoFastMathFlags a b []
