module CodeGen.Block where

import Control.Monad.State

import Data.Map as Map
import Data.List
import Data.Function
import Data.Ord

import LLVM.AST
import LLVM.AST.Global
import qualified LLVM.AST as AST

import CodeGen.State as S
import CodeGen.Module

generateBlock :: Int -> BlockState
generateBlock size = BlockState size [] Nothing

getName :: String -> Names -> (String, Names)
getName name names =
  case Map.lookup name names of
    Nothing -> (name,  Map.insert name 1 names)
    Just elem -> (name ++ show elem, Map.insert name (elem + 1) names)

addBlock :: String -> CodeGen Name
addBlock name = do
    names <- gets names
    blocks <- gets blocks
    nbBlocks <- gets nbBlocks
    let block = generateBlock nbBlocks
        (name', supply) = getName name names
    modify $ \lambda ->
        lambda {
            names = supply,
            blocks = Map.insert (mkName name') block blocks,
            nbBlocks = nbBlocks + 1
        }
    return (mkName name')

editBlock :: BlockState -> CodeGen()
editBlock block = do
    current <- gets currentBlock
    modify $ \lambda ->
        lambda {blocks = Map.insert current block (blocks lambda)}

setBlock :: Name -> CodeGen Name
setBlock name = do
    modify $ \lambda ->
        lambda {currentBlock = name}
    return name

getActiveBlock :: CodeGen BlockState
getActiveBlock = do
    current <- gets currentBlock
    blocks <- gets blocks
    case Map.lookup current blocks of
        Just elem -> return elem
        Nothing -> error $ "No block found with identifier: " ++ show current


sortBlocks :: [(Name, BlockState)] -> [(Name, BlockState)]
sortBlocks = sortBy (compare `on` (S.index . snd))

genBlock :: (Name, BlockState) -> BasicBlock
genBlock (name, BlockState _ stack terminator) = BasicBlock name (reverse stack) (maketerm terminator)
  where
    maketerm Nothing = error $ "Block has no terminator: " ++ show name
    maketerm (Just x) = x

createBlocks :: CodeGenerationState -> [BasicBlock]
createBlocks state = Prelude.map genBlock $ sortBlocks $ Map.toList (blocks state)