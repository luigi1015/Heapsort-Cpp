all: Test countingsort.o

countingsort.o: countingsort.cpp
	g++ -Wall -c countingsort.cpp

Test: countingsort.cpp test.cpp
	g++ -Wall -std=c++11 -o Test test.cpp

clean:
	rm Test *.o *~
