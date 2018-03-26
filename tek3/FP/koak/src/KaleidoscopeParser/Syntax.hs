module KaleidoscopeParser.Syntax where

import ParserCombinator.Parser

type Name = String
type Op = String

data Expr = Float Double
          | Number Integer
          | ConstString String
          | ConstChar Char
          | BinOp Op Expr Expr
          | Var String
          | Prototype String [Expr] Type
          | Condition Expr Expr Expr
          | VarType Type String
          | Def Expr Expr --Prototype
          | CallExpr String [Expr]
          | Extern Expr --Prototype
          | Boolean Bool
          deriving (Eq, Ord, Show)

data Precedence = AssocLeft Int | AssocRight Int
                  deriving (Eq, Show, Ord)

data Operator = Operator Op Precedence
                deriving (Eq, Show)

instance Ord Operator where
    (Operator _ value1) `compare` (Operator _ value2) = value1 `compare` value2

data Type = Void
          | Int
          | Double
          | Char
          deriving (Eq, Ord, Show)
