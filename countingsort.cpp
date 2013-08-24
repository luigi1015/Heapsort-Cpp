#include <vector>

namespace countingsort
{
	template <class T> void countingsort( std::vector<T> input, std::vector<T> &output, T highest )
	{//Counting sort. It assumes the input is a set of unsigned integer-like variables. It takes an input vector, an output vector and the highest integer in the set.
		std::vector<unsigned int> temp( highest+1, 0 );//Holds a count of how many times each value is in input. Initializes the vector with highest+1 elements of value 0.
		output.resize( input.size() );//Resize output to the size of input.
		
		for( unsigned int i = 0; i < input.size(); i++ )
		{//Add 1 to the corresponding element in temp each time you come across a value in the input. After the loop is finished, temp has the number of elements in input with a value equal to the index of the temp element.
			temp.at( input.at(i) )++;
		}
		
		for( unsigned int i = 1; i <= highest; i++ )
		{//Adds the previous values to the temp elements so that each temp element has the number of elements in input less than or equal to the value of that index.
			temp.at(i) = temp.at(i) + temp.at(i-1);
		}
		
		for( int i = input.size() - 1; i >= 0; i-- )
		{
			output.at( temp.at( input.at(i) )-1 ) = input.at(i);
			temp.at( input.at(i) )--;
		}
	}
}
