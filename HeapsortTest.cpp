#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include "Heapsort.cpp"
#include <vector>

class HeapsortTest : public CppUnit::TestCase 
{
	private:
		
	public:
		
		void testSortBasic()
		{//Basic test of the Counting Sort. Just makes sure it will sort a vector of 1 through 6.
			Heapsort::heap<unsigned int> A;
			
			A.items.push_back(5);
			A.items.push_back(2);
			A.items.push_back(4);
			A.items.push_back(6);
			A.items.push_back(1);
			A.items.push_back(3);
			
			A.heapSize = A.items.size()-1;
			
			Heapsort::heapsort<unsigned int>(A);
			
			for( unsigned int i = 0; i < A.items.size(); i++ )
			{//Check every element of A to make sure it has sorted values 1..n where n is the number of elements.
				CPPUNIT_ASSERT( A.items.at(i) == i+1 );
			}
		}
		
		//Create the test suite using CPPUnit macros.
		CPPUNIT_TEST_SUITE( HeapsortTest );
		CPPUNIT_TEST( testSortBasic );
		//CPPUNIT_TEST_EXCEPTION( testPossibleOutOfRangeLower, std::out_of_range );
		//CPPUNIT_TEST_EXCEPTION( testPossibleOutOfRangeUpper, std::out_of_range );
		CPPUNIT_TEST_SUITE_END( );
};

int main( )
{
	CPPUNIT_TEST_SUITE_REGISTRATION( HeapsortTest );
	CppUnit::TextUi::TestRunner runner;
	CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry( );
	runner.addTest( registry.makeTest( ) );
	if ( runner.run( ) )
	{//Runner had success.
		return 0;
	}
	else
	{//Runner failed.
		return 1;
	}
}
