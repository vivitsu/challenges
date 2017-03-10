isPrime :: Integer -> Bool
isPrime k = null [ x | x <- [2..intSqrt k], k `mod` x  == 0]
  where intSqrt k = floor . sqrt $ fromIntegral k

sumOfPrimes :: Integer -> Integer
sumOfPrimes n = sum $ filter isPrime [2..n]
