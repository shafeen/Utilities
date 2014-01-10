
// #include "DebugLogger.h"
#include "HashMap.h"
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

void hashMapMultiNodeInsertTest()
{
	HashMap<int> *map = new HashMap<int>(100);

	// insert a bunch // <<
	map->insert(string("key1"), 1);  
	map->insert(string("key2"), 2);  
	map->insert(string("key3"), 3);  
	map->insert(string("key4"), 4);  
	map->insert(string("key5"), 5);  
	map->insert(string("key6"), 6);  
	map->insert(string("key7"), 7);  
	map->insert(string("key8"), 8);  
	map->insert(string("key9"), 9);  
	
}

void hashMapInsertAndRemoveTest()
{
	HashMap<int> *map = new HashMap<int>(100);

	// insert a bunch // <<
	map->insert(string("key1"), 1);  
	map->insert(string("key2"), 2);  
	map->insert(string("key3"), 3);  
	map->insert(string("key4"), 4);  
	cout << "CURRENT NODES " << map->size() << endl;

	assert(map->remove("key5") == false);
	cout << "CURRENT NODES " << map->size() << endl;

	assert(map->remove("key4") == true);
	assert(map->remove("key4") == false);
	cout << "CURRENT NODES " << map->size() << endl;

	assert(map->find("key1") != nullptr);
	assert(map->find("key2") != nullptr);
	assert(map->find("key3") != nullptr);
	assert(map->find("key4") == nullptr);

}


int main()
{
	// testMapNode();	
	// hashMapInsertTest();
	// hashMapMultiNodeInsertTest();
	hashMapInsertAndRemoveTest();

}

