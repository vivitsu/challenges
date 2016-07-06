-- The following iterative sequence is defined for the set of positive integers:

-- n → n/2 (n is even)
-- n → 3n + 1 (n is odd)

-- Using the rule above and starting with 13, we generate the following sequence:

-- 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
-- It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms.
-- Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

-- Which starting number, under one million, produces the longest chain?

-- NOTE: Once the chain starts the terms are allowed to go above one million.

import Data.List
import Data.Ord

-- OLD VERSION
{--
max' :: [(Int, Int)] -> (Int, Int)
max' [] = error "Max of Empty List"
max' (x:xs) = go x xs
    where go m [] = m
          go m@(e,l) (y@(e',l'):ys) = if l > l' then go m ys else go y ys

collatzTuple :: Int -> (Int, Int)
collatzTuple x = let xs = collatzList x
                 in (head xs, length xs)

solution :: Int
solution = fst $ max' [collatzTuple t | t <- [1..999999]]
--}

collatzNext :: Int -> Int
collatzNext n | odd n = (3 * n) + 1
              | even n = div n 2

-- TODO: Remove hard coding the fact that all sequences end at 1
collatzList :: Int -> [Int]
collatzList 1 = [1]
collatzList s = s : collatzList (collatzNext s)

max' :: [Int] -> (Int, Int)
max' xs = maximumBy (comparing fst) (zip xs [1..])

solution :: Int
solution = let xs = [length $ collatzList x | x <- [1..999999]]
           in snd $ max' xs
