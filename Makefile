all: Test heapsort.o

heapsort.o: heapsort.cpp
	g++ -Wall -c heapsort.cpp

Test: heapsort.cpp test.cpp
	g++ -Wall -o Test test.cpp

clean:
	rm Test *.o *~
