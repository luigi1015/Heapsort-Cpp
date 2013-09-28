all: Test Heapsort.o

Heapsort.o: Heapsort.cpp
	g++ -Wall -c Heapsort.cpp

Test: Heapsort.cpp HeapsortTest.cpp
	g++ -Wall -o Test HeapsortTest.cpp -lcppunit

clean:
	rm Test *.o *~
