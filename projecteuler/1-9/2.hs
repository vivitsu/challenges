fib :: Int -> Int
fib 1 = 1
fib 2 = 2
fib n = fib (n-1) + fib (n-2)

fibList :: [Int]
fibList = [fib x | x <- [1..]]

evenFibSum :: Int
evenFibSum = sum [x | x <- takeWhile (< 4000000) fibList, even x]

