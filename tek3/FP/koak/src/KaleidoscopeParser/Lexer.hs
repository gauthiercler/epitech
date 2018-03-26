module KaleidoscopeParser.Lexer (
    integer,
    float,
    identifier,
    reserved,
    parens,
    commaSep,
    semiSep,
    operatorParserList,
    operator
) where

import Control.Applicative
import Control.Monad
import ParserCombinator.Parser
import ParserCombinator.Combinators
import KaleidoscopeParser.Syntax

-- integer <- (+/-)? [0-9]+
integer :: Parser Integer
integer = do
          o <- string "+" <|> string "-" <|> return []
          s <- some digit
          return $ value o s
          where
            value "+" s = read (s)::Integer
            value o s = read (o++s)::Integer

-- simple_float <- (+/-)? [0-9]+ '.' [0-9]*
simpleFloat :: Parser Double
simpleFloat = do
              o <- string "+" <|> string "-" <|> return []
              s <- some digit
              cs <- string "."
              xs <- many digit
              return $ value o s cs xs
                where
                    value "+" s _ [] = read (s)::Double
                    value "+" s cs xs = read (s++cs++xs)::Double
                    value o s _ [] = read (o++s)::Double
                    value o s cs xs = read (o++s++cs++xs)::Double

-- short_float <- (+/-)? '.' [0-9]+
shortFloat :: Parser Double
shortFloat = do
             o <- string "+" <|> string "-" <|> return []
             s <- string "."
             cs <- some digit
             return $ value o s cs
             where
                value "+" s cs = read ("0"++s++cs)::Double
                value o s cs = read (o++"0"++s++cs)::Double

-- float <- short_float / simple_float
float :: Parser Double
float = do
        s <- shortFloat <|> simpleFloat
        return $ s

-- identifier  <- [a-zA-Z][a-zA-Z0 -9]*
identifier :: Parser String
identifier = do
            s <- alpha
            cs <- many alphaNum
            return $ (s:cs)

-- Take Between parentheses
parens :: Parser a -> Parser a
parens m = do
    reserved "("
    n <- m
    reserved ")"
    return n

-- Get all parser separated by ,
commaSep :: Parser a -> Parser [a]
commaSep p = sepBy p (reserved ",")

-- Get all parser separated by ;
semiSep :: Parser a -> Parser [a]
semiSep p = sepBy p (reserved ";")

-- Create binary operator
binary :: String -> Precedence -> Parser Operator
binary s p = do
             reserved s
             return $ Operator s p

-- List of operator parser
operatorParserList :: [Parser Operator]
operatorParserList = [
           binary "+=" (AssocRight 10),
           binary "-=" (AssocRight 10),
           binary "*=" (AssocRight 10),
           binary "/=" (AssocRight 10),
           binary "%=" (AssocRight 10),
           binary "<<=" (AssocRight 10),
           binary ">>=" (AssocRight 10),
           binary "&=" (AssocRight 10),
           binary "^=" (AssocRight 10),
           binary "|=" (AssocRight 10),
           binary "||" (AssocLeft 20),
           binary "&&" (AssocLeft 30),
           binary "|" (AssocLeft 40),
           binary "^" (AssocLeft 50),
           binary "&" (AssocLeft 60),
           binary "<<" (AssocLeft 90),
           binary ">>" (AssocLeft 90),
           binary "==" (AssocLeft 70),
           binary "=" (AssocRight 10),
           binary "!=" (AssocLeft 70),
           binary "<=" (AssocLeft 80),
           binary ">=" (AssocLeft 80),
           binary "<" (AssocLeft 80),
           binary ">" (AssocLeft 80),
           binary "+" (AssocLeft 80),
           binary "-" (AssocLeft 80),
           binary "*" (AssocLeft 80),
           binary "/" (AssocLeft 80),
           binary "%" (AssocLeft 80),
           binary "+" (AssocLeft 100),
           binary "-" (AssocLeft 100),
           binary "*" (AssocLeft 110),
           binary "/" (AssocLeft 110),
           binary "%" (AssocLeft 110)
         ]

-- check binop
operator :: Parser Operator
operator = choice operatorParserList