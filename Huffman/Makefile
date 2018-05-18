#File: Makefile
#Class: CS 215                       Instructor: Dr. Deborah Hwang
#Assignment: Project 6               Date assigned: April 19, 2017
#Programmer: Abdulaziz Alshabibi     Date completed: April 29, 2017

coder: coder.o huffman.o
	clang++ -Wall -g -o coder coder.o huffman.o

coder.o: coder.cpp huffman.h
	clang++ -Wall -g -c coder.cpp

huffman.o: huffman.cpp huffman.h
	clang++ -Wall -g -c huffman.cpp
