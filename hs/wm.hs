import Control.Monad
import Data.List
import Text.Printf

wm :: [Integer] -> [Integer] -> Double
wm arr wts = fromInteger (sum $ zipWith (\e1 e2 -> e1 * e2) arr wts) / (fromInteger $ sum wts)

main :: IO()
main = do{
    _ <- readLn :: IO Int;
    arr <- getLine;
    wts <- getLine;
    printf "%.1f\n" $ wm (map (\e -> (read e):: Integer) (words arr)) (map (\e -> (read e):: Integer) (words wts))
}

