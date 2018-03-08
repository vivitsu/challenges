-- URL: http://www.reddit.com/r/dailyprogrammer/comments/2zyipu/20150323_challenge_207_easy_bioinformatics_1_dna/

-- DNA - deoxyribonucleic acid - is the building block of every organism.
-- It contains information about hair color, skin tone, allergies, and more.
-- It's usually visualized as a long double helix of base pairs.
-- DNA is composed of four bases - adenine, thymine, cytosine, guanine -
-- paired as follows: A-T and G-C.

-- Meaning: on one side of the strand there may be a series of bases

-- A T A A G C

-- And on the other strand there will have to be

-- T A T T C G

-- It is your job to generate one side of the DNA strand and output the two
-- DNA strands.

-- Your program should take a DNA sequence as input and return the
-- complementary strand.

-- Sample Input: A A T G C C T A T G G C

-- Sample Output:
-- A A T G C C T A T G G C
-- T T A C G G A T A C C G

import System.Environment
import qualified Data.Map as Map

-- Insert DNA codon table here as Map, and then do lookup
myMap = Map.fromList [("TTT", "Phe"),
                      ("TTC", "Phe"),
                      ("TTA", "Leu"),
                      ("TTG", "Leu"),
                      ("CTT", "Leu"),
                      ("CTC", "Leu"),
                      ("CTA", "Leu"),
                      ("CTG", "Leu"),
                      ("ATT", "Ile"),
                      ("ATC", "Ile"),
                      ("ATA", "Ile"),
                      ("ATG", "Met"),
                      ("GTT", "Val"),
                      ("GTC", "Val"),
                      ("GTA", "Val"),
                      ("GTG", "Val"),
                      ("TCT", "Ser"),
                      ("TCC", "Ser"),
                      ("TCA", "Ser"),
                      ("TCG", "Ser"),
                      ("CCT", "Pro"),
                      ("CCC", "Pro"),
                      ("CCA", "Pro"),
                      ("CCG", "Pro"),
                      ("ACT", "Thr"),
                      ("ACC", "Thr"),
                      ("ACA", "Thr"),
                      ("ACG", "Thr"),
                      ("GCT", "Ala"),
                      ("GCC", "Ala"),
                      ("GCA", "Ala"),
                      ("GCG", "Ala"),
                      ("TAT", "Ty"),
                      ("TAC", "Ty"),
                      ("TAA", "STOP"),
                      ("TAG", "STOP"),
                      ("CAT", "His"),
                      ("CAC", "His"),
                      ("CAA", "Gln"),
                      ("CAG", "Gln"),
                      ("AAT", "Asn"),
                      ("AAC", "Asn"),
                      ("AAA", "Lys"),
                      ("AAG", "Lys"),
                      ("GAT", "Asp"),
                      ("GAC", "Asp"),
                      ("GAA", "Glu"),
                      ("GAG", "Glu"),
                      ("TGT", "Cys"),
                      ("TGC", "Cys"),
                      ("TGA", "STOP"),
                      ("TGG", "Trp"),
                      ("CGT", "Arg"),
                      ("CGC", "Arg"),
                      ("CGA", "Arg"),
                      ("CGG", "Arg"),
                      ("AGT", "Ser"),
                      ("AGC", "Ser"),
                      ("AGA", "Arg"),
                      ("AGG", "Arg"),
                      ("GGT", "Gly"),
                      ("GGC", "Gly"),
                      ("GGA", "Gly"),
                      ("GGG", "Gly")]

pair :: Char -> Char
pair c = case c of
          'A' -> 'T'
          'T' -> 'A'
          'C' -> 'G'
          'G' -> 'C'

-- splitAt n xs can be thought of as (take n xs, drop n xs)
split :: Int -> [Char] -> [[Char]]
split _ [] = []
split n xs = first : (split n rest)
  where
    (first, rest) = splitAt n xs

-- Need to put in checks for START and STOP codons
get :: [[Char]] -> [Maybe [Char]]
get [] = []
get (x:xs) = let val = Map.lookup x myMap
             in (val : get xs)

-- Since 'getArgs' returns [String], d is a String, or [Char]
-- Unfortunately, this will print values like [Just "STOP", etc..]
main = do [d] <- getArgs
          putStrLn d
          putStrLn $ map pair d
          putStrLn $ show (get (split 3 d))
