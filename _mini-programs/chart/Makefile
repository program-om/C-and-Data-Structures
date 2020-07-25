
driver: driver.o chart.o
	clang++ -g -Wall -o driver driver.o chart.o

driver.o: driver.cpp chart.h
	clang++ -g -Wall -c driver.cpp

chart.o: chart.cpp chart.h
	clang++ -g -Wall -c chart.cpp

clean:
	rm -f *.o driver *~

run:
	./driver