
#include "HashMap.h"

using namespace shafeen;


template <class HashValue>
HashMap<HashValue>::HashMap()
{
	this->HashMap(100);
}

template <class HashValue>
HashMap<HashValue>::HashMap(size_t suggestedCapacity)
: mapNodesInHashMap(0)
{
	currentCapacity = this->findFirstPrimeAbove(suggestedCapacity);

	/* init empty array of current capacity */
	hashMapArray = new MapNode<HashValue> * [currentCapacity];
	for(unsigned int mapEntry = 0; mapEntry < currentCapacity; mapEntry++)
		hashMapArray[mapEntry] = nullptr;

}




template <class HashValue>
HashMap<HashValue>::~HashMap()
{
	for(unsigned int mapEntry = 0; mapEntry < currentCapacity; mapEntry++)
		if(hashMapArray[mapEntry])
			delete hashMapArray[mapEntry];
	
	delete[] hashMapArray;
}




template <class HashValue>
MapNode<HashValue> * HashMap<HashValue>::find(string key)
{	
	unsigned int mapIndexForKey = findBucketToStoreKey(key);

	MapNode<HashValue> *foundEntry = nullptr;
	if (hashMapArray[mapIndexForKey]->key == key) 
		foundEntry = hashMapArray[mapIndexForKey];

	return foundEntry;
}




template <class HashValue>
bool HashMap<HashValue>::insert(MapNode<HashValue> *node)
{	
	unsigned int mapIndexForKey = findBucketToStoreKey(node->key);

	MapNode<HashValue> *hashMapEntry = hashMapArray[mapIndexForKey];
	if(hashMapEntry) // for now collisions will cause insert to fail -> db
	{
		std::cerr << "<insert> Collision Occurred\n";
		return false;
	}
	else
	{
		hashMapEntry = node;
		mapNodesInHashMap++;
	}
}

template <class HashValue>
bool HashMap<HashValue>::insert(string key, HashValue value)
{	
	MapNode<HashValue> *node = new MapNode<HashValue>(key, value);
	this->insert(node);
}




template <class HashValue>
unsigned int HashMap<HashValue>::hash31Function(string key)
{
	unsigned int hashValue = 0; 

	unsigned int keySize = key.size();
	for(unsigned int i = 0; i < keySize; i++)
		hashValue += (unsigned int)key[i]*31;

	return hashValue;
}




template <class HashValue>
unsigned int HashMap<HashValue>::findBucketToStoreKey(string key)
{
	return (this->hash31Function(key) % currentCapacity);		
}





template <class HashValue>
unsigned int HashMap<HashValue>::findFirstPrimeAbove(unsigned int number)
{
	return number; // TEMPORARY!! db		
}






