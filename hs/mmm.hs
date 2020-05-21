import Control.Monad
import Data.List
import Text.Printf

avg :: Int -> [Integer] -> Double
avg n ys = fromInteger (sum ys) / fromIntegral n

median :: Int -> [Integer] -> Double
median 1 [x] = fromInteger x
median n xs
    | n `mod` 2 == 1 = fromInteger $ head $ drop (n `div` 2) xs
    | otherwise = avg 2 (take 2 (drop ((n `div` 2) - 1) xs))

hsort :: [Integer] -> [Integer]
hsort [] = []
hsort [x] = [x]
hsort [x, y]
    |  x <= y = [x, y]
    | otherwise = [y, x]
hsort (x:xs) = hsort( (filter (x >=) xs) ++ [x]) ++ hsort(filter (x <) xs)

modeHelper :: [Integer] -> (Integer, Int) -> (Integer, Int)
modeHelper arr t2
  | length arr > snd t2 = (head arr, length arr)
  | length arr < snd t2 = t2
  | head arr < fst t2 = (head arr, length arr)
  | otherwise = t2

mode :: [Integer] -> Integer
mode xs = fst (foldr (\e a-> modeHelper e a) (0, 0) (groupBy (==) xs))

---------- Usage ------------------
calc :: Int -> [Integer] -> String
calc n arr = (printf "%.1f" (avg n sarr)) ++ "\n" ++ (printf "%.1f" (median n sarr)) ++ "\n" ++ show(mode sarr)
              where sarr = Data.List.sort arr

main :: IO()
main = do{
    n <- readLn :: IO Int;
    sa <- getLine;
    putStrLn (calc n (map (\e -> (read e):: Integer) (words sa)));
}

