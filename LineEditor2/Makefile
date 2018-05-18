#File: Makefile
#Class: CS 215                       Instructor: Dr. Deborah Hwang
#Assignment: Project 3               Date assigned: Feb 22, 2017
#Programmer: Abdulaziz Alshabibi     Date completed: March 15, 2017

editor: editor2.o document2.o
	clang++ -Wall -g -o editor2 editor2.o document2.o

editor2.o: editor2.cpp document2.h
	clang++ -Wall -g -c editor2.cpp

document2.o: document2.cpp document2.h
	clang++ -Wall -g -c document2.cpp
