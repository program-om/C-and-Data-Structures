#File: Makefile
#Class: CS 215                     Instructor: Dr. Deborah Hwang
#Assignment:Project 2              Date assigned: Feb  , 2017 
#Programmer: Abdulaziz Alshabibi   Date completed: Feb 15, 2017

settester: settester.o setcard.o
	clang++ -Wall -o settester settester.o setcard.o

settester.o: settester.cpp setcard.h
	clang++ -Wall -c settester.cpp

setcard.o: setcard.cpp setcard.h
	clang++ -Wall -c setcard.cpp
