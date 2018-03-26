module ParserCombinator.Parser
    (
    Parser,
    item,
    sat,
    runParser,
    failure,
    empty,
    ) where

import Control.Monad
import Control.Applicative

newtype Parser a = Parser { parse :: String -> [(a, String)]}

runParser :: Parser a -> String -> a
runParser m s =
    case parse m s of
        [(res, [])] -> res
        [(_, rs)] -> error $ "Parser did not consume entire stream. \"" ++ rs ++ "\""
        _ -> error "Parser error."

-- return the first letter and the rest of the stream
item :: Parser Char
item = Parser $ \s -> case s of
                        (c:cs) -> [(c, cs)]
                        _ -> []


-- Concat two parsing rule to one list
bind :: Parser a -> (a -> Parser b) -> Parser b
bind p f = Parser $ \s -> concatMap (\(a, s') -> parse (f a) s') $ parse p s

-- Return parser type
unit :: a -> Parser a
unit a = Parser (\s -> [(a, s)])

-- Functor for parser -> fmap take function and applicate it on Parser type
instance Functor Parser where
    fmap f (Parser cs) = Parser (\s -> [(f a, b) | (a, b) <- cs s])

instance Applicative Parser where
    pure = return
    (Parser cs1) <*> (Parser cs2) = Parser (\s -> [(f a, s2) | (f, s1) <- cs1 s, (a, s2) <- cs2 s1])

instance Monad Parser where
    return = unit
    (>>=) = bind

instance MonadPlus Parser where
    mzero = failure
    mplus = combine

instance Alternative Parser where
    empty = mzero
    (<|>) = option

-- Combine two parser function over the same string and concatenate
combine :: Parser a -> Parser a -> Parser a
combine p q = Parser (\s -> parse p s ++ parse q s)

-- If return [] parser fail
failure :: Parser a
failure = Parser (\cs -> [])

-- If first parse function return [] go on next and parse other
option :: Parser a -> Parser a -> Parser a
option p q = Parser $ \s -> case parse p s of
                                [] -> parse q s
                                res -> res

-- Satisfy function that take Char and return a bool
sat :: (Char -> Bool) -> Parser Char
sat p = item >>= \c -> if p c
                           then unit c
                           else (Parser (\cs -> []))

