#ifndef _HASHMAP_H_
#define _HASHMAP_H_

#include "MapNode.h"
#include <string>
#include <vector>

using namespace std;

namespace shafeen
{
	
template<class HashValue>
class HashMap
{
public:
	HashMap();
	HashMap(size_t suggestedCapacity);
	virtual ~HashMap();

	// returns false if insert fails
	// insert will fail if node exists
	bool insert(MapNode<HashValue> *mapNode);
	bool insert(string key, HashValue value);

	// returns the MapNode * associated with this key
	// returns nullptr if key not found
	MapNode<HashValue> * find(string key);

	// returns the number of MapNodes contained
	size_t size(){return mapNodesInHashMap;}

	// disable copy constructor and assignment operator
	HashMap(const HashMap&) = delete;
	HashMap& operator=(const HashMap&) = delete;


private:
	size_t mapNodesInHashMap;
	size_t currentCapacity;

	// The actual HashMap container
	MapNode<HashValue> **hashMapArray;

	unsigned int findBucketToStoreKey(string key);
	
	unsigned int hash31Function(string key);
	
	unsigned int findFirstPrimeAbove(unsigned int number);


};


} /* namespace shafeen */

#endif