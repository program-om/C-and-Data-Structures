# Timer makefile

driver: driver.o timer.o
	clang++ -Wall -g -o driver.o timer.o

driver.o: driver.cpp timer.h 
	clang++ -Wall -g -c driver.cpp

timer.o: timer.cpp timer.h
	clang++ -Wall -g -c timer.cpp
