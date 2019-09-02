#pragma once
#include "assert.h"

#include "MemoryLeakTester.h"

class DynamicArray
{
	private:
		int* alocatedSpace;	// stored ins
		int totalMemoryAllocated;		// total able to be stored
		int count;			// Total values stored

	public:
		//Initialising
		// Constructors
		DynamicArray();

		DynamicArray(int initial);
		// Destructor
		~DynamicArray();
		// Assignment operator
		DynamicArray& operator=(const DynamicArray& other);
		// Copy Constructor
		DynamicArray(const DynamicArray& other);
		// [] operator overrides
		int& operator[](int index);

		const int& operator[](int index) const;

		// add to middle of array
		void addAtIndex(int value, int index);

		// add to end of array
		void pushToEnd(int value);
		// remove from end
		void removeFromEnd();

		// remove element at place position and copy rest of the values in order back
		void orderedRemove(int index);
		// Copy last element to pisition and reduce count of total elements
		void unorderedRemove(int index);

		//  Array can store this many but this isn't how many elements their actually is
		void reserveTotal(int size);

		void reserveExtra(int extra);


		// clear the array
		void clearAll();
		void clear();

		bool operator==(DynamicArray);
		bool operator!=(DynamicArray);

		// returns how many elements there are
		int getCount();

		// returns the current cappacity of the array
		int getCapacity();
};

