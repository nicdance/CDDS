#include "DynamicArray.h"
//Initialising
// Constructors
DynamicArray::DynamicArray():DynamicArray(1) //Sets up a default size
{
}

DynamicArray::DynamicArray(int initial) {
	if (initial > 0) {
		totalMemoryAllocated = initial;
		count = 0;
		alocatedSpace = new int[initial];
		for (int i = 0; i < initial; i++) {
			alocatedSpace[i] = 0; // Fill the array with a default value of 0
		}
	}
	else {
		alocatedSpace = nullptr;
	}
}
// Destructor
DynamicArray::~DynamicArray()
{
	delete[] alocatedSpace;
}
// Assignment operator
DynamicArray& DynamicArray::operator=(const DynamicArray& other) {
	if (totalMemoryAllocated < other.count) {
		reserveExtra(other.totalMemoryAllocated - totalMemoryAllocated);
	}
	for (int i = 0; i < other.count; i++)
	{
		alocatedSpace[i] = other.alocatedSpace[i];
	}
	return *this;
}
// Copy Constructor
DynamicArray::DynamicArray(const DynamicArray& other) : DynamicArray(other.count) {
	for (int i = 0; i < totalMemoryAllocated; i++) {
		alocatedSpace[i] = other.alocatedSpace[i];
	}
}

// [] operator overrides
int& DynamicArray::operator[](int index) {
	if ((index + 1) > totalMemoryAllocated) {
		reserveExtra(5);			// need to decide if only 1 extra space is allocated or 5? 10? more?
	}
	if (index + 1 > count) {
		count = index + 1;
	}
	return alocatedSpace[index]; // returned as a reference
}

const int& DynamicArray::operator[](int index) const {
	assert(index < totalMemoryAllocated - 1);
	return alocatedSpace[index]; // returned as a reference
}




// add to middle of array
void DynamicArray::addAtIndex(int value, int index) {
	reserveExtra(1);
	for (int i = count; i > index; i--) {
		alocatedSpace[i] = alocatedSpace[i - 1];
	}
	alocatedSpace[index] = value;
}


// add to end of array
void DynamicArray::pushToEnd(int value) {
	reserveExtra(1);
	alocatedSpace[count] = value;
	count++;
}
// remove from end
void DynamicArray::removeFromEnd() {
	alocatedSpace[count - 1] = 0;
	count--;
}


// remove element at place position and copy rest of the values in order back
void DynamicArray::orderedRemove(int index) {
	count--;
	for (int i = index; i < count; i++) {
		alocatedSpace[i] = alocatedSpace[i + 1];
	}
}
// Copy last element to pisition and reduce count of total elements
void DynamicArray::unorderedRemove(int index) {
	if (index < (count - 1)) {
		alocatedSpace[index] = alocatedSpace[count - 1];
		removeFromEnd();
	}
}


//  Array can store this many but this isn't how many elements their actually is
void DynamicArray::reserveTotal(int size) {
	if (size < totalMemoryAllocated) {
		return;
	}
	// allocate new array
	int *temp = new int[size];
	// Copy Balues from old to new Array
	for (int i = 0; i < count; i++) {
		temp[i] = alocatedSpace[i];
	}
	for (int i = count; i < size; i++) {
		temp[i] = 0;
	}
	delete[] alocatedSpace;
	alocatedSpace = temp;
	totalMemoryAllocated = size;
}


void DynamicArray::reserveExtra(int extra) {
	reserveTotal(count + extra);
}


// clear the array
void DynamicArray::clearAll() {
	count = 0;
	totalMemoryAllocated = 0;
	delete[] alocatedSpace;
	alocatedSpace = nullptr;
}
void DynamicArray::clear() {
	count = 0;
}

bool DynamicArray::operator==(DynamicArray) {
	return true;	// temp value so will compile
}
bool DynamicArray::operator!=(DynamicArray) {
	return true;	// temp value so will compile
}

// returns how many elements there are
int DynamicArray::getCount() {
	return count;
}

// returns the current cappacity of the array
int DynamicArray::getCapacity() {
	return totalMemoryAllocated;
}