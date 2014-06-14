#ifndef STACK_H_
#define STACK_H_

namespace shafeen {
namespace data_structures {

#include "LinkedList.h"

template<class T>
class LinkedList;

template <class T>
class Stack {

protected:
	// doubly LinkedList used as data structure
	LinkedList<T> *dList; 

	unsigned int size;

public:
	Stack();
	virtual ~Stack();

	void push(T *datum, bool heapAllocated);
	T * pop(); // returns a STRONG ptr 

	bool isEmpty() {return size == 0;}
	unsigned int getSize() {return size;}
};



} /* namespace data_structures */
} /* namespace shafeen */

#endif /* STACK_H_ */