#ifndef _HASHMAP_H_
#define _HASHMAP_H_

#include "MapNode.h"
#include "DebugLogger.h"
#include <string>
#include <vector>

using namespace std;
using namespace shafeen::debug;

namespace shafeen {
namespace data_structures {
	
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

	// removes the [key, value] pair associated 
	// with the "key" argument -> if one exists 
	// false -> key does not exist 
	// true  -> key exists and pair removed
	bool remove(string key);


	// returns the number of MapNodes contained
	size_t size(){return mapNodesInHashMap;}
	size_t capacity(){return currentCapacity;}

	void enableDebugOutput();
	void disableDebugOutput();

	// disable copy & move constructors
	// and their assignment operators
	HashMap(const HashMap&) = delete;
	HashMap& operator=(const HashMap&) = delete;
	HashMap(const HashMap&&) = delete;
	HashMap& operator=(const HashMap&&) = delete;


private:
	size_t mapNodesInHashMap;
	size_t currentCapacity;

	// The actual HashMap array container
	MapNode<HashValue> **hashMapArray;

	unsigned int findBucketToStoreKey(string key);
	
	unsigned int hash31Function(string key);
	
	unsigned int findFirstPrimeAbove(unsigned int number);


};

} /* namespace data_structures */
} /* namespace shafeen */

#endif