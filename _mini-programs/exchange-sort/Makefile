# File: Makefile
# Class: CS 215
# Assignment: Practical Exam 2, Problem 1
# Date: March 28 & 30, 2017

exchange-sort: exchange-sort.o
	g++ -g -Wall -o exchange-sort exchange-sort.o

exchange-sort.o: exchange-sort.cpp
	g++ -g -Wall -c exchange-sort.cpp

clean:
	rm -f *.o exchange-sort *~

run:
	./exchange-sort list.dat output.dat

