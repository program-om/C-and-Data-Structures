#File: Makefile
#Class: CS 215                       Instructor: Dr. Deborah Hwang
#Assignment: Project 6               Date assigned: April 7, 2017
#Programmer: Abdulaziz Alshabibi     Date completed: April 17, 2017

editor: editor.o document.o
	clang++ -Wall -g -o editor editor.o document.o

editor.o: editor.cpp document.h
	clang++ -Wall -g -c editor.cpp

document.o: document.cpp document.h
	clang++ -Wall -g -c document.cpp
