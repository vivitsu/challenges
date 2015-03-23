-- URL: http://www.reddit.com/r/dailyprogrammer/comments/2zyipu/20150323_challenge_207_easy_bioinformatics_1_dna/

-- DNA - deoxyribonucleic acid - is the building block of every organism. It contains information about hair color, skin tone, allergies, and more.
-- It's usually visualized as a long double helix of base pairs.
-- DNA is composed of four bases - adenine, thymine, cytosine, guanine - paired as follows: A-T and G-C.
-- Meaning: on one side of the strand there may be a series of bases

-- A T A A G C

-- And on the other strand there will have to be

-- T A T T C G

-- It is your job to generate one side of the DNA strand and output the two DNA strands.
-- Your program should take a DNA sequence as input and return the complementary strand.

-- Sample Input: A A T G C C T A T G G C

-- Sample Output:
-- A A T G C C T A T G G C
-- T T A C G G A T A C C G
import System.Environment

pair :: Char -> Char
pair c = case c of
          'A' -> 'T'
          'T' -> 'A'
          'C' -> 'G'
          'G' -> 'C'

-- Since 'getArgs' returns [String], d is a String, or [Char]
main = do [d] <- getArgs
          putStrLn d
          putStrLn $ fmap pair d
