
#include "Animal.h"


Animal::Animal()
: call("default call"),
  name("Animal") 
{}

Animal::~Animal()
{}

void Animal::animalCall()
{
	cout << call << endl;
}


void Animal::animalName()
{
	cout << name << endl;
}


