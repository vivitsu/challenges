module LeapYear (isLeapYear) where

isDivisibleBy4 :: Integer -> Bool
isDivisibleBy4 year = if f == 0 then True else False
  where f = fromIntegral $ year `mod` 4

isNotDivisibleBy100 :: Integer -> Bool
isNotDivisibleBy100 year = if f == 0 then False else True
  where f = fromIntegral $ year `mod` 100

isDivisibleBy400 :: Integer -> Bool
isDivisibleBy400 year = if f == 0 then True else False
  where f = fromIntegral $ year `mod` 400

isLeapYear :: Integer -> Bool
isLeapYear year = if isDivisibleBy4 year then
                    if isNotDivisibleBy100 year then
                      True
                    else
                      if isDivisibleBy400 year then
                        True
                      else
                        False
                  else
                    False
