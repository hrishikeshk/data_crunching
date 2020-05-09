module Gcd (sim_gcd, x_gcd) where

sim_gcd' :: Int -> Int -> Int
sim_gcd' a b
  | a == 0 = b
  | otherwise = sim_gcd' (b `mod` a) a

sim_gcd :: Int -> Int -> Int
sim_gcd a b = sim_gcd' (abs a) (abs b)

type G = Int
type X = Int
type Y = Int
-- G = a.X + b.Y

x_gcd :: Int -> Int -> (G, (X, Y))
x_gcd a b
  | b == 0 = (a, (1, 0))
  | otherwise = (g, (x, y))
    where (g, (x', y')) = x_gcd b (a `mod` b)
          x = y'
          y = x' - (a `div` b) * y'

