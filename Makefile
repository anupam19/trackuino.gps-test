gps-test: gps-test.o gps.o
	g++ -o gps-test gps-test.o gps.o

gps-test.o: gps-test.cpp
	g++ -c gps-test.cpp

gps.o: gps.cpp gps.h
	g++ -c gps.cpp

.PHONY clean:
	rm *.o gps-test

