-- https://projecteuler.net/problem=5

-- 2520 is the smallest number that can be divided by each of the numbers
-- from 1 to 10 without any remainder.

-- What is the smallest positive number that is evenly divisible by all of the
-- numbers from 1 to 20?
myGcd :: (Integral a) => a -> a -> a
myGcd a 0 = a
myGcd a b = myGcd b (a `rem` b)

myLcm :: (Integral a) => a -> a -> a
myLcm x y = (x*y) `div` myGcd x y

lcm' :: (Integral a) => a
lcm' = foldl myLcm 1 [2..20]
