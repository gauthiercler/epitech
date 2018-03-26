
module CodeGen.Generation where


import CodeGen.Module
import CodeGen.Instructions.Instructions

import CodeGen.State
import Control.Monad.State
import LLVM.AST.Name

import Data.Map as Map

entryBlockName :: String
entryBlockName = "entry"

generateEmptyCodegen :: CodeGenerationState
generateEmptyCodegen = CodeGenerationState Map.empty 0 1 [] Map.empty (mkName entryBlockName)

execCodeGen :: CodeGen a -> CodeGenerationState
execCodeGen m = execState (startCodeGen m) generateEmptyCodegen
