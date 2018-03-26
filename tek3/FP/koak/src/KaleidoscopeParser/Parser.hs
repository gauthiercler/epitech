module KaleidoscopeParser.Parser (
    int,
    floating,
    variable,
    typing,
    extern,
    toplevel,
    commaSep,
    binop,
    unary,
    expr,
    defn
) where

import Control.Monad
import Control.Applicative
import ParserCombinator.Parser
import ParserCombinator.Combinators
import KaleidoscopeParser.Lexer
import KaleidoscopeParser.Syntax
import qualified Data.Map as Map
import Data.Map ((!))

-- int ::= integer
int :: Parser Expr
int = do
      n <- integer
      return $ Number n

-- floating ::= float
floating :: Parser Expr
floating = do
           n <- float
           return $ Float n

-- variable ::= identifier
variable :: Parser Expr
variable = do
           n <- identifier
           return $ Var n

-- constchar ::= '"' (. !'"')* '"'
conststring :: Parser Expr
conststring = do
              spaces
              char '"'
              s <- (many $ noneOf "\"")
              char '"'
              spaces
              return $ ConstString s

-- constchar ::= '\'' (. !'\'') '\''
constchar :: Parser Expr
constchar = do
            spaces
            char '\''
            s <- noneOf "'"
            char '\''
            spaces
            return $ ConstChar s

-- boolean ::= "false" | "true"
boolean :: Parser Expr
boolean = do
          s <- string "false" <|> string "true"
          return $ Boolean $ getBool s
          where
            getBool "false" = False
            getBool "true" = True

-- typing ::= "void" | "int" | "double" | "char"
typing :: Parser Type
typing = do
         n <- string "void" <|> string "int" <|> string "double" <|> string "char"
         spaces
         return $ getType n
         where
            getType "void" = Void
            getType "int" = Int
            getType "double" = Double
            getType "char" = Char

-- vartype ::= identifier ":" type
vartype :: Parser Expr
vartype = do
          name <- identifier
          reserved ":"
          typ <- typing
          return $ VarType typ name

-- extern ::= "extern" prototype
extern :: Parser Expr
extern = do
         reserved "extern"
         proto <- prototype
         return $ Extern proto

-- functiondefinition ::= "def" prototype expr
def :: Parser Expr
def = do
      reserved "def"
      spaces
      p <- prototype
      s <- expr
      return $ Def p s

-- prototype ::= identifier '(' (expr (, expr)*)? ')' ":" type
prototype :: Parser Expr
prototype = do
            name <- identifier
            args <- parens $ commaSep vartype
            reserved ":"
            typ <- typing
            return $ Prototype name args typ

-- defn ::= extern | def | expr
defn :: Parser Expr
defn = extern <|> def <|> expr

-- unary ::= primary
unary :: Parser Expr
unary = do
        s <- primary
        return s

-- ifexpr ::= if expr then expr else expr
ifexpr :: Parser Expr
ifexpr = do
         reserved "if"
         s1 <- expr
         reserved "then"
         s2 <- expr
         reserved "else"
         s3 <- expr
         return $ Condition s1 s2 s3

-- expr ::= unary (#binop unary)*
expr :: Parser Expr
expr = binop unary (AssocLeft 0)

-- callexpr ::= identifier '(' (expr (',' expr)* )? ')'
callexpr :: Parser Expr
callexpr = do
           i <- identifier
           exprs <- parens $ commaSep expr
           return $ CallExpr i exprs

-- primary ::= callexpr | parenexpr | variable | ifexpr | forexpr | integer | decimal | char | string | boolean
primary :: Parser Expr
primary = do
          s <- parens expr <|> ifexpr <|> boolean <|> callexpr <|> variable <|> conststring <|> constchar <|> floating <|> int
          return s

-- Top level of kaleidoscope language !
toplevel :: Parser [Expr]
toplevel = many $ do
                  spaces
                  def <- defn
                  reserved ";"
                  return def

-- List of operator with association and precedence
operatorList :: [Operator]
operatorList = [
                Operator "+=" (AssocRight 10),
                Operator "-=" (AssocRight 10),
                Operator "*=" (AssocRight 10),
                Operator "/=" (AssocRight 10),
                Operator "%=" (AssocRight 10),
                Operator "<<=" (AssocRight 10),
                Operator ">>=" (AssocRight 10),
                Operator "&=" (AssocRight 10),
                Operator "^=" (AssocRight 10),
                Operator "|=" (AssocRight 10),
                Operator "||" (AssocLeft 20),
                Operator "&&" (AssocLeft 30),
                Operator "|" (AssocLeft 40),
                Operator "^" (AssocLeft 50),
                Operator "&" (AssocLeft 60),
                Operator "<<" (AssocLeft 90),
                Operator ">>" (AssocLeft 90),
                Operator "==" (AssocLeft 70),
                Operator "=" (AssocRight 10),
                Operator "!=" (AssocLeft 70),
                Operator "<=" (AssocLeft 80),
                Operator ">=" (AssocLeft 80),
                Operator "<" (AssocLeft 80),
                Operator ">" (AssocLeft 80),
                Operator "+" (AssocLeft 80),
                Operator "-" (AssocLeft 80),
                Operator "*" (AssocLeft 80),
                Operator "/" (AssocLeft 80),
                Operator "%" (AssocLeft 80),
                Operator "+" (AssocLeft 100),
                Operator "-" (AssocLeft 100),
                Operator "*" (AssocLeft 110),
                Operator "/" (AssocLeft 110),
                Operator "%" (AssocLeft 110)
          ]

-- Get precedence of an operator
operatorInfoPrecedence :: Operator -> Precedence
operatorInfoPrecedence (Operator _ p) = p

-- Create map with name and operator informations
operatorMap :: Map.Map String Operator
operatorMap = Map.fromList (map mkOpInfoTuple operatorList)
    where
        mkOpInfoTuple opInfo@(Operator name _) = (name, opInfo)

-- Get precedence of an operator name
operatorPrecedence :: String -> Precedence
operatorPrecedence name = operatorInfoPrecedence (operatorMap ! name)

-- Precedence climbing
operatorWithPrecedence :: Int -> Parser Operator
operatorWithPrecedence min = do
                             op <- operator
                             case operatorPrecedence (getOpName op) of
                                AssocLeft precedence
                                    | precedence >= min -> return op
                                AssocRight precedence
                                    | precedence >= min -> return op
                                _ -> failure
                            where
                                getOpName (Operator name _) = name

-- Create precedence climbing tree with precedence and type of expr
binop :: Parser Expr -> Precedence -> Parser Expr
binop p precedence = do
                     u <- p
                     parseInfix (precedenceValue precedence) p u
                     where
                        precedenceValue (AssocLeft n) = n + 1
                        precedenceValue (AssocRight n) = n

-- Create binary operator expr
parseStdOp :: Operator -> Expr -> Parser Expr -> Parser Expr
parseStdOp (Operator name precedence) lhs p = do
                                              rhs <- binop p (precedence)
                                              return (BinOp name lhs rhs)

-- Bind operator left assoc
bindOperatorLeft :: String -> Expr -> Parser Expr -> Parser Expr
bindOperatorLeft name lhs p =
    case (Map.lookup name operatorMap) of
        Just opInfo -> parseStdOp opInfo lhs p
        Nothing -> error $ "Unknown operator \"" ++ name ++ "\""

-- Parser infix with precendece
parseInfix :: Int -> Parser Expr -> Expr -> Parser Expr
parseInfix precedence p lhs = do
                              maybeOp <- optionMaybe(operatorWithPrecedence precedence)
                              case maybeOp of
                                (Just name) -> bindOperatorLeft (getOpName name) lhs p >>= parseInfix precedence p
                                Nothing -> return lhs
                              where
                                getOpName (Operator name _) = name
