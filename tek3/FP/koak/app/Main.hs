module Main where

import KaleidoscopeParser.Parser
import KaleidoscopeParser.Syntax
import KaleidoscopeParser.Lexer
import ParserCombinator.Parser
import Control.Monad
import Control.Monad.Trans
import System.IO
import System.Environment

import CodeGen.Module

import CodeGen.Emitter
import qualified LLVM.AST as AST
import LLVM.AST


import qualified Data.ByteString.Char8 as B

getASTs :: String -> [Expr]
getASTs = runParser toplevel

run :: Module -> String -> IO Module
run mod value = codegen mod ast
            where
                ast = getASTs value

workwithline :: Module -> IO Module
workwithline mod = do
                   putStr "> "
                   hFlush stdout
                   line <- getLine
                   mod' <- run mod line
                   workwithline mod'

workwithfile :: String -> IO Module
workwithfile filename = do
                        s <- readFile filename
                        run (emptyModule "module 1.0") s
main :: IO Module
main = do
         args <- getArgs
         if null args then
            workwithline $ emptyModule "module 1.0"
         else do
            let (file:_) = args
            workwithfile file
