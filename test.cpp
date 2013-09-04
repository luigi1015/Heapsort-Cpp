#include <vector>
#include "heapsort.cpp"
#include <iostream>

template <class T> void printVector( std::vector<T> items )
{//Print a vector, one item per line.
	for( unsigned int i = 0; i < items.size(); i++ )
	{
		std::cout << items.at(i) << " ";
	}
	std::cout << std::endl;
}

int main( int argc, const char* argv[] )
{//Test out the Insertion Sort.
	/*
	std::vector<int> A;
	A.push_back(5);
	A.push_back(2);
	A.push_back(4);
	A.push_back(6);
	A.push_back(1);
	A.push_back(3);
	*/
	
	heapsort::heap<int> A;
	A.items.push_back(5);
	A.items.push_back(2);
	A.items.push_back(4);
	A.items.push_back(6);
	A.items.push_back(1);
	A.items.push_back(3);
	
	A.heapSize = A.items.size()-1;
	
	std::cout << "Before sort:" << std::endl;
	printVector<int>(A.items);
	std::cout << std::endl;
	
	heapsort::heapsort<int>(A);
	
	std::cout << "After sort:" << std::endl;
	printVector<int>(A.items);
	
	return 0;
}
