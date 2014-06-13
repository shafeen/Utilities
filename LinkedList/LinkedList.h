#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_ 

namespace shafeen {
namespace data_structures {


template <class T>
class LinkedList {

public:
	T *nodeData;
	LinkedList *next;

	// this variable will indicate whether the nodeData stored in this
	// LinkedList is heap allocated, useful when destructor is called
	const bool heapAllocated;

public:

	// "heapAllocated" MUST be set by the user for deallocation safety
	LinkedList(T *nodeData, bool heapAllocated);
	virtual ~LinkedList();

	LinkedList<T> *getTailNode();
};	


} /* namespace data_structures */
} /* namespace shafeen */


#endif /* LINKEDLIST_H_ */