module SpaceAge (Planet(..), ageOn) where

data Planet = Earth
            | Mercury
            | Venus
            | Mars
            | Jupiter
            | Saturn
            | Uranus
            | Neptune

conversionFactor :: Planet -> Planet -> Float
conversionFactor Earth Earth = 1.0
conversionFactor Mercury Earth = 0.2408467
conversionFactor Venus Earth = 0.61519726
conversionFactor Mars Earth = 1.8808158
conversionFactor Jupiter Earth = 11.862615
conversionFactor Saturn Earth = 29.447498
conversionFactor Uranus Earth = 84.016846
conversionFactor Neptune Earth = 164.79132

ageOnEarth :: Float -> Float
ageOnEarth seconds = seconds / 31557600

ageOn :: Planet -> Float -> Float
ageOn planet seconds = (ageOnEarth seconds) / (conversionFactor planet Earth)
