#include "MapNode.h"
#include "HashMap.h"

#include <iostream>
#include <cstdio>
// #include <thread>
// #include <mutex>
#include <cassert>
#include "HashMap.h"

using namespace std;
using namespace shafeen;

void testMapNode()
{
	string key("key1");
	int value = 1;
	
	shafeen::MapNode<int> node1(key, value);

	printf("key: %s\tvalue: %d\n", node1.key.c_str(), node1.value);
}


void hashMapInsertTest()
{
	string key("key1");
	int value = 1;
	
	MapNode<int> *node1 = new MapNode<int>(key, value);

	shafeen::HashMap<int> *map = new shafeen::HashMap<int>();

	// map->insert(node1); // << 

	// MapNode<int> *nodeptr1 = map.find(key); // << 
	// assert(nodeptr1 != nullptr);

	// MapNode<int> *nodeptr2 = map.find(string("unknownKey"));
	// assert(nodeptr2 == nullptr);

	// cout << nodeptr1->value << endl;

}


int main()
{
	// testMapNode();	
	hashMapInsertTest();



}