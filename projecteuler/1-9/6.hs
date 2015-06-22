-- The sum of the squares of the first ten natural numbers is,

-- 1^2 + 2^2 + ... + 10^2 = 385

-- The square of the sum of the first ten natural numbers is,

-- (1 + 2 + ... + 10)^2 = 55^2 = 3025

-- Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is

-- 3025 − 385 = 2640.

-- Find the difference between the sum of the squares of the first one hundred natural numbers and
-- the square of the sum.

sumOfSquares :: Integer
sumOfSquares = foldr (\x y -> x*x + y) 0 [1..100]

squareOfSum :: Integer
squareOfSum = sums * sums
    where sums = sum [1..100]

sumSquareDiff :: Integer
sumSquareDiff = subtract sumOfSquares squareOfSum
