module CodeGen.Instructions.References where

import LLVM.AST
import LLVM.AST.Type
import LLVM.AST.Constant

-- Generate LLVM constant reference from identifier

-- generate local reference
localReference :: Name -> Operand
localReference = LocalReference double

-- generate extern reference
externReference :: LLVM.AST.Type -> LLVM.AST.Name -> Operand
externReference ty nm = ConstantOperand (GlobalReference ty nm)

-- generate global reference
globalReference :: Name -> Constant
globalReference = GlobalReference double

-- generate constant reference
constantReference :: Constant -> Operand
constantReference = ConstantOperand