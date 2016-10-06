-- http://stackoverflow.com/questions/4541415/haskell-prime-test
isPrime :: Integer -> Bool
isPrime x = null $ filter divisible $ takeWhile notTooBig [2..]
    where divisible y = x `mod` y == 0
          notTooBig y = y*y <= x

soln :: Int -> Integer
soln n = last . take n . filter isPrime $ [2,3..]
