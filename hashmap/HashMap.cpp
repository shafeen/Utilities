
#include "HashMap.h"
#include <cassert>


namespace shafeen {
namespace data_structures {

template <class HashValue>
HashMap<HashValue>::HashMap()
{
	currentCapacity = this->findFirstPrimeAbove(100);
	DebugLogger::getInstance() << "Current capacity is " << currentCapacity << endl; // db
	/* init empty array of current capacity */
	hashMapArray = new MapNode<HashValue> * [currentCapacity];
	for(unsigned int mapEntry = 0; mapEntry < currentCapacity; mapEntry++)
		hashMapArray[mapEntry] = nullptr;
}

template <class HashValue>
HashMap<HashValue>::HashMap(size_t suggestedCapacity)
{
	currentCapacity = this->findFirstPrimeAbove(suggestedCapacity);
	DebugLogger::getInstance() << "Current capacity is " << currentCapacity << endl; // db
	
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



// transfers ownership for now when it should not -> should be const *
template <class HashValue>
MapNode<HashValue> * HashMap<HashValue>::find(string key)
{	
	DebugLogger::getInstance() << "Searching for key: " << key.c_str() << endl; 

	unsigned int mapIndexForKey = findBucketToStoreKey(key);

	MapNode<HashValue> *foundEntry = nullptr;
	if (hashMapArray[mapIndexForKey] && hashMapArray[mapIndexForKey]->key == key) 
		foundEntry = hashMapArray[mapIndexForKey];
	else
		DebugLogger::getInstance() << "Key not found!\n";

	return foundEntry;
}

template <class HashValue>
bool HashMap<HashValue>::remove(string key)
{	
	MapNode<HashValue> *foundEntry = this->find(key);
	if (foundEntry)
	{
		unsigned int indexForKey = findBucketToStoreKey(key); 
		DebugLogger::getInstance()<< "<remove> Removing node @ "<< indexForKey << endl;
		
		delete foundEntry;
		hashMapArray[indexForKey] = nullptr;
		mapNodesInHashMap--;
		return true;
	}

	return false;
}




template <class HashValue>
bool HashMap<HashValue>::insert(MapNode<HashValue> *node)
{	
	unsigned int mapIndexForKey = findBucketToStoreKey(node->key);
	DebugLogger::getInstance() << "@ index: " << mapIndexForKey << endl; // db


	MapNode<HashValue> *&hashMapEntry = hashMapArray[mapIndexForKey];
	if(hashMapEntry != nullptr) // for now collisions cause insert to fail -> db
	{
		DebugLogger::getInstance() << "<insert> Collision Occurred\n";
		return false;
	}
	else
	{
		assert(hashMapEntry == nullptr);
		assert(node != nullptr);

		DebugLogger::getInstance()<< "<insert> Node Inserted @ "<< mapIndexForKey << endl;
		hashMapEntry = node;
		mapNodesInHashMap++;
		return true;
	}
}

template <class HashValue>
bool HashMap<HashValue>::insert(string key, HashValue value)
{	
	MapNode<HashValue> *node = new MapNode<HashValue>(key, value);
	return(this->insert(node));
}




template <class HashValue>
unsigned int HashMap<HashValue>::hash31Function(string key)
{
	unsigned int hashValue = 0; 

	unsigned int keySize = key.size();
	for(unsigned int i = 0; i < keySize; i++)
	{
		hashValue += (unsigned int)key[i]*31;
	}
	return hashValue;
}




template <class HashValue>
unsigned int HashMap<HashValue>::findBucketToStoreKey(string key)
{
	DebugLogger::getInstance() << "finding bucket for key...\n"; // db
	unsigned int bucketNum = hash31Function(key) % currentCapacity; 
	DebugLogger::getInstance() << "bucketNum = "<< bucketNum << "\n"; // db
	return bucketNum;		
}





template <class HashValue>
unsigned int HashMap<HashValue>::findFirstPrimeAbove(unsigned int number)
{
	// DebugLogger::getInstance() << "returning number "<< number << endl;
	return number; // TEMPORARY!! db		
}


template <class HashValue>
void HashMap<HashValue>::enableDebugOutput()
{
	DebugLogger::getInstance().setOutputStream(&std::cout);	
}
template <class HashValue>
void HashMap<HashValue>::disableDebugOutput()
{
	DebugLogger::getInstance().setOutputStream(nullptr);
}


} /* namespace data_structures */
} /* namespace shafeen */

