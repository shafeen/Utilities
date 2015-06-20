
#include "LinkedList.h"
#include "Stack.h"
#include <iostream>
#include <string>


using namespace std;
using namespace shafeen::data_structures;


void test1() // linkedlist
{	
	// populate a simple integer LinkedList
	int data = 0;
	LinkedList<int> *l = new LinkedList<int>(new int(0), true);

	// we are using an inefficient pushBack strategy
	for(int i = 1; i < 10; i++)
	{
		l->getTailNode()->next = new LinkedList<int>(new int(i), true);
	}

	// verify that everything was populated
	LinkedList<int> *head = l;
	while(head)
	{
		cout << *(head->nodeData) << endl;
		head = head->next;
	}
}

void test2() // stack
{	
	// populate a simple integer Stack
	int data = 0;
	Stack<int> *l = new Stack<int>();

	// push back numbers 0-9 in order
	for(int i = 0; i < 10; i++)
	{
		l->push(new int(i), true);
	}

	// verify that stack->pop() works!
	// should print from 9-0
	int *popped;
	while((popped = l->pop()))
		cout << *popped << endl;

}

void test3() // stack
{	
	// populate a simple integer Stack
	Stack<string> *l = new Stack<string>();

	l->push(new string("Hello"), true);
	l->push(new string("World"), true);

	// verify that stack->pop() works!
	// should print World Hello
	string *popped;
	while((popped = l->pop()))
		cout << *popped << endl;

}


int main(int argc, char const *argv[])
{
	test3();
	return 0;
}