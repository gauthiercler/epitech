module ParserCombinator.Combinators (
    oneOf,
    noneOf,
    chainl,
    char,
    natural,
    string,
    ascii,
    alpha,
    alphaNum,
    space,
    digit,
    notAscii,
    notAlpha,
    notAlphaNum,
    notSpace,
    notDigit,
    spaces,
    token,
    sepBy,
    sepBy1,
    reserved,
    choice,
    option,
    optionMaybe
) where

import Data.Char
import Control.Monad
import Control.Applicative
import ParserCombinator.Parser

-- Verify char is one of list of char
oneOf :: [Char] -> Parser Char
oneOf s = sat (flip elem s)

-- Verify char is not one of list of char
noneOf :: [Char] -> Parser Char
noneOf s = sat $ not . flip elem s

-- Seperate zero or more occurence of p separate by op
chainl :: Parser a -> Parser (a -> a -> a) -> a -> Parser a
chainl p op a = (p `chainl1` op) <|> return a

-- Seperate one or more occurence of p separate by op
chainl1 :: Parser a -> Parser (a -> a -> a) -> Parser a
p `chainl1` op = do {a <- p; rest a}
                 where rest a = (do f <- op
                                    b <- p
                                    rest (f a b)) <|> return a

-- Verify is a Char
char :: Char -> Parser Char
char c = sat (c ==)

-- Verify is Integer
natural :: Parser Integer
natural = read <$> some (sat isDigit)

-- Verify is String
string :: String -> Parser String
string [] = return []
string (c:cs) = do { char c; string cs; return (c:cs) }

-- Verify is ascii
ascii :: Parser Char
ascii = sat isAscii

-- Verify is ascii
notAscii :: Parser Char
notAscii = sat $ not . isAscii

-- Verify is space
space :: Parser Char
space = sat isSpace

-- Verify is not space
notSpace :: Parser Char
notSpace = sat $ not . isSpace

-- Verify is alpha
alpha :: Parser Char
alpha = sat isAlpha

-- Verify is not alpha
notAlpha :: Parser Char
notAlpha = sat $ not . isAlpha

-- Verify is alphanumeric
alphaNum :: Parser Char
alphaNum = sat isAlphaNum

-- Verify is not alphanumeric
notAlphaNum :: Parser Char
notAlphaNum = sat $ not . isAlphaNum

-- Verify is digit
digit :: Parser Char
digit = sat isDigit

-- Verify is not digit
notDigit :: Parser Char
notDigit = sat $ not . isDigit

-- Verify spaces " \n\r"
spaces :: Parser String
spaces = many $ oneOf " \t\n\r"

-- Take token and remove space
token :: Parser a -> Parser a
token p = do { spaces; a <- p; spaces ; return a}

-- Take reserved
reserved :: String -> Parser String
reserved s = token (string s)

-- Separate with separator -> zero or more
sepBy :: Parser a -> Parser b -> Parser [a]
sepBy p sep = sepBy1 p sep <|> return []

-- Separate with separator -> one or more
sepBy1 :: Parser a -> Parser b -> Parser [a]
sepBy1 p sep = do
               x <- p
               xs <- many (do {sep; p})
               return (x:xs)

-- Apply the parsers in the list ps until one of them succeeds. (Return succeed)
choice :: [Parser a] -> Parser a
choice ps = foldr (<|>) mzero ps

-- Option combinator
option :: a -> Parser a -> Parser a
option x p = p <|> return x

-- Option Maybe (Return Nothing if not okay)
optionMaybe :: Parser a -> Parser (Maybe a)
optionMaybe p = option Nothing (liftM Just p)