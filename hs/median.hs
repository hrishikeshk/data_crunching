type Len = Int
type Mids a = (a, a)

fs_traverse' :: [a] -> [a] -> (Len, Mids a) -> (Len, Mids a)
fs_traverse' _ [] ja = ja
fs_traverse' (x1:x2:xs) [w] (l, (xa, xb)) = (l + 1, (x1, x2))
fs_traverse' (x1:x2:xs) ys (l, (xa, xb)) = fs_traverse' (x2:xs) (drop 2 ys) (l + 2, (x1, x2))

fs_traverse :: [a] -> (Len, Mids a)
fs_traverse x'@(x1:x2:xs) = fs_traverse' (drop 1 x') (drop 2 x') (2, (x1, x2))

ev_od :: (Len, (Double, Double)) -> Double
ev_od tup
  | (fst tup) `mod` 2 == 0 = ((fst (snd tup) + snd (snd tup)) / 2)
  | otherwise = fst (snd tup)

median :: [Double] -> Maybe Double
median [] = Nothing
median [x] = Just x
median xs = Just (ev_od (fs_traverse xs) )

main = print(median [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11])

