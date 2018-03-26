module CodeGen.Module where

import CodeGen.State

import LLVM.AST
import LLVM.AST.Global
import qualified LLVM.AST as AST

import Data.String

import Control.Monad.State
import Control.Applicative

-- exec Monad state with endState Module
startLLVM :: AST.Module -> LLVM Type -> AST.Module
startLLVM modul (LLVM m) = execState m modul

-- add a new Module
addModule :: Definition -> LLVM ()
addModule element = do
  defs <- gets moduleDefinitions
  modify $ \lambda ->
    lambda { moduleDefinitions = defs ++ [element] }

-- Generate LLVM definition
newDefinition :: Type -> String -> [(Type, Name)] -> [BasicBlock] -> Definition
newDefinition retType name args body =
    GlobalDefinition $ functionDefaults {
        name = mkName name,
        parameters = (
        [
            Parameter type' name' []
            | (type', name') <- args
        ], False),
        basicBlocks = body,
        returnType = retType
    }

-- define function block
define :: Type -> String -> [(Type, Name)] -> [BasicBlock] -> LLVM()
define retType name args body = addModule $ newDefinition retType name args body

-- import external definition
extern :: Type -> String -> [(Type, Name)] -> LLVM()
extern retType name args = addModule $ newDefinition retType name args []

-- Create an empty module with label name
emptyModule :: String -> AST.Module
emptyModule label = defaultModule { moduleName = fromString label }
