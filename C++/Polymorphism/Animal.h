#ifndef _ANIMAL_H_
#define _ANIMAL_H_

#include <iostream>
#include <string>
using namespace std;

class Animal {
public:
	Animal();
	virtual ~Animal();

	virtual void animalCall();
	virtual void animalName();

protected: 
	string call;
	string name;


};




#endif