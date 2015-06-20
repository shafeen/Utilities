#include "LinkedList.h"	
#include <cassert>
#include <iostream>
#include <string>

using std::string;

namespace shafeen {
namespace data_structures {
	
template <class T>
LinkedList<T>::LinkedList(T *_nodeData, bool _heapAlloc)
: nodeData(_nodeData),
  next(nullptr),
  prev(nullptr), 
  heapAllocated(_heapAlloc)
{}
template LinkedList<int>::LinkedList(int *_nodeData, bool _heapAlloc);
template LinkedList<string>::LinkedList(string *_nodeData, bool _heapAlloc);

template <class T>
LinkedList<T>::~LinkedList()
{
	// cascading deallocation starting from
	// this node of our current LinkedList
	// taking care to ONLY call "delete" on
	// heap allocated nodeData
	LinkedList *head = this;
	while(head != nullptr)
	{
		if(head->heapAllocated)
			delete head->nodeData;
		head = head->next;
	}
}
template LinkedList<int>::~LinkedList();
template LinkedList<string>::~LinkedList();

template <class T>
LinkedList<T> * LinkedList<T>::getTailNode()
{
	LinkedList<T> *head = this;
	while(head->next)
		head = head->next;
	return head;
}
template LinkedList<int> * LinkedList<int>::getTailNode();
template LinkedList<string> * LinkedList<string>::getTailNode();



} /* namespace data_structures */
} /* namespace shafeen */