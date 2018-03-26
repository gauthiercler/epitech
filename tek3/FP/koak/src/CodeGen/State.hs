{-# LANGUAGE GeneralizedNewtypeDeriving #-}

module CodeGen.State where

import Data.Map

import LLVM.AST
import LLVM.AST.Global
import qualified LLVM.AST as AST

import Control.Monad.State
import Control.Applicative

type SymbolTable = [(String, Operand)]
type Blocks = Map Name BlockState
type Names = Map String Int

-- CodeGeneration
data CodeGenerationState = CodeGenerationState {
    names :: Names,
    count :: Int,
    nbBlocks :: Int,
    symbolTable :: SymbolTable,
    blocks :: Blocks,
    currentBlock :: Name
} deriving (Show)

-- Basic block inside function definitions
data BlockState = BlockState {
    index :: Int, -- Block Index
    stack :: [Named Instruction], -- Instructions which need name
    terminator :: Maybe (Named Terminator) -- Define end of the block
} deriving (Show)

newtype CodeGen newType = CodeGen {
    startCodeGen :: State CodeGenerationState newType
} deriving (
        MonadState CodeGenerationState,
        Monad,
        Applicative,
        Functor
    )

newtype LLVM newType = LLVM (State AST.Module newType)
    deriving (
        MonadState AST.Module,
        Monad,
        Applicative,
        Functor
    )