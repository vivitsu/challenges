-- Find the largest palindrome made from the product of 2 3-digit numbers
intToList :: Int -> [Int]
intToList = reverse . helper
    where helper 0 = []
          helper x = (x `rem` 10) : helper (x `div` 10)

isPalindrome :: Int -> Bool
isPalindrome x
    | xs == reverse xs = True
    | otherwise = False
  where xs = intToList x

largestPalindrome :: Int
largestPalindrome = maximum $ filter isPalindrome [x*y | x <- [100..999], y <- [100..999]]
