#ifndef _MAP_NODE_H_
#define _MAP_NODE_H_

#include <string>
#include <iostream>

namespace shafeen 
{

template <class T>
class MapNode 
{
public:
	
	const std::string key;
	const T value;

	MapNode *prev;
	MapNode *next;

	MapNode(std::string _key, T _value)
	: key(_key), 
	  value(_value), 
	  prev(nullptr),
	  next(nullptr)
	  {};

};


}  /* namespace shafeen */



#endif