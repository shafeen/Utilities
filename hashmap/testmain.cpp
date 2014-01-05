
#include "HashMap.cpp"
#include <iostream>
#include <cstdio>
#include <cassert>

using namespace std;
using namespace shafeen::data_structures;

void printNode(MapNode<int> *node)
{
	printf("key: %s\tvalue: %d\n", node->key.c_str(), node->value);
}

void testMapNode()
{
	string key("key1");
	int value = 1;
	
	MapNode<int> node1(key, value);

	printNode(&node1);
}


void hashMapInsertTest()
{
	string key("key1");
	int value = 1;
	
	MapNode<int> *node1 = new MapNode<int>(key, value);

	HashMap<int> *map = new HashMap<int>(100);
	cout << "CURRENT CAPACITY " << map->capacity() << endl;
	map->insert(key, value); // << 
	cout << "CURRENT NODES " << map->size() << endl;
	map->insert(key, 2); // << 
	cout << "CURRENT NODES " << map->size() << endl;

	MapNode<int> *nodeptr1 = map->find(key); // << 
	assert(nodeptr1 != nullptr);
	cout << "FOUND: ";
	printNode(nodeptr1);

	MapNode<int> *nodeptr2 = map->find(string("1key"));
	assert(nodeptr2 == nullptr);


}


int main()
{
	// testMapNode();	
	hashMapInsertTest();



}