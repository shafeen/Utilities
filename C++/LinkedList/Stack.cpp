#include "LinkedList.h"
#include "Stack.h"

#include <string>
using std::string;

namespace shafeen {
namespace data_structures {


template <class T>
Stack<T>::Stack()
: dList(nullptr), // lazy allocation
  size(0)
{}	
template Stack<int>::Stack();
template Stack<string>::Stack();

template <class T>
Stack<T>::~Stack()
{
	if(this->dList)
		delete this->dList;
}
template Stack<int>::~Stack();
template Stack<string>::~Stack();

template <class T>
void Stack<T>::push(T *datum, bool heapAllocated)
{
	if(!this->dList)
		dList = new LinkedList<T>(datum, heapAllocated);
	else
	{
		LinkedList<T> *temp = new LinkedList<T>(datum, heapAllocated);
		temp->next = this->dList;
		this->dList->prev = temp;
		this->dList = temp;
	}

	this->size++;
}
template void Stack<int>::push(int *datum, bool heapAllocated);
template void Stack<string>::push(string *datum, bool heapAllocated);


template <class T>
T * Stack<T>::pop()
{
	if(this->dList)
	{	
		T *temp = dList->nodeData;
		if((dList = dList->next))
			dList->prev = nullptr;

		this->size--;
		return temp;
	}

	return nullptr;
}
template int * Stack<int>::pop();
template string * Stack<string>::pop();


} /* namespace data_structures */
} /* namespace shafeen */