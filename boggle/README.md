## What's this program about ?
first five lines will be letters. The rest of the lines will be words to look for in the boggle

## Game explanation
Provided a square grid of random letters, the program will try to find the words are given according to the following rules. The program will start from the first letter in the word and then will try to find the second letter in one of the eight letters around the first letter. This process will continue until the last letter found. If one of the letters is not found then the word can't found.

## how to run the program?
- clang++ boggle.cpp boggle

- ./boggle inputFile outputFile
