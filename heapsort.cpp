#include <vector>

namespace heapsort
{
	template <class T> struct heap
	{//A data structure to hold a very basic heap.
		std::vector<T> items;
		unsigned int heapSize;
	};
	
	int parent( int i )
	{//Returns the index of the parent of the item at index i. It should return the value of i/2 rounded down, but since C++ does round down integer division anyway nothing more needs to be done.
		return i/2;
	}
	
	int left( int i )
	{//Returns the index of the left child of the item at index i.
		return 2*i+1;
	}
	
	int right( int i )
	{//Returns the index of the right child of the item at index i.
		return 2*i + 2;
	}

	template <class T> void swap( heap<T> &theHeap, int firstIndex, int secondIndex )
	{//Swap items at first and second index.
		T tempVal = theHeap.items.at(firstIndex);
		theHeap.items.at(firstIndex) = theHeap.items.at(secondIndex);
		theHeap.items.at(secondIndex) = tempVal;
	}
	
	template <class T> void maxHeapify( heap<T> &theHeap, int index )
	{//Function for making sure that items[i] is in the right spot for the tree rooted there to be a max-heap. It assumes the left and right child trees are already max-heaps.
		int largest = 0;
		int l = left(index);
		int r = right(index);
		
		if( l >= (int)theHeap.items.size() )
		{
			l = theHeap.items.size() - 1;
		}
		
		if( r >= (int)theHeap.items.size() )
		{
			r = theHeap.items.size() - 1;
		}
		
		if( (l < (int)theHeap.heapSize) && (theHeap.items.at(l) > theHeap.items.at(index)) )
		{
			largest = l;
		}
		else
		{
			largest = index;
		}
		
		if( (r < (int)theHeap.heapSize) && (theHeap.items.at(r) > theHeap.items.at(largest)) )
		{
			largest = r;
		}
		
		if( largest != index )
		{
			swap( theHeap, index, largest );
			maxHeapify( theHeap, largest );
		}
	}
	
	template <class T> void buildMaxHeap( heap<T> &theHeap )
	{//Function for building a max-heap out of a regular vector from the bottom up using maxHeapify. Since the elements after (the length of the array)/2 are leaves anyway by the structure of the heap, they don't need to be converted and are ignored by this function.
		theHeap.heapSize = theHeap.items.size();
		for( int i = theHeap.items.size()/2-1; i >= 0; i-- )
		{
			maxHeapify( theHeap, i );
		}
	}
	
	template <class T> void heapsort( heap<T> &theHeap )
	{//Function for building a max-heap out of a regular vector from the bottom up using maxHeapify. Since the elements after (the length of the array)/2 are leaves anyway by the structure of the heap, they don't need to be converted and are ignored by this function.
		buildMaxHeap( theHeap );
		
		for( int i = theHeap.items.size()-1; i >= 1; i-- )
		{
			swap( theHeap, 0, i );
			theHeap.heapSize--;
			maxHeapify( theHeap, 0);
		}
	}
}
