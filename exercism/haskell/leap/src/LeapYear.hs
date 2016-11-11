module LeapYear (isLeapYear) where

isLeapYear :: Integer -> Bool
isLeapYear year | year `isDivisibleBy` 400 = True
                | year `isDivisibleBy` 100 = False
                | year `isDivisibleBy` 4 = True
                | otherwise = False
                where isDivisibleBy year num = year `mod` num == 0
