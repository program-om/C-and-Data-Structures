#File: Makefile
#Class: CS 215                       Instructor: Dr. Deborah Hwang
#Assignment: Project 4               Date assigned: March 17, 2017
#Programmer: Abdulaziz Alshabibi     Date completed: March 27, 2017

sweeper: sweeper.o sweepercell.o sweepergrid.o
	clang++ -Wall -g -o sweeper sweeper.o sweepercell.o sweepergrid.o

sweeper.o: sweeper.cpp sweepercell.h sweepergrid.h
	clang++ -Wall -g -c sweeper.cpp

sweepercell.o: sweepercell.cpp sweepercell.h
	clang++ -Wall -g -c sweepercell.cpp

sweepergrid.o: sweepergrid.cpp sweepergrid.h sweepercell.h
	clang++ -Wall -g -c sweepergrid.cpp

clean:
	rm -f *.o listdriver *~
