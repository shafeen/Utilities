
#include <iostream>
#include "Animal.h"
#include "Cow.h"

using namespace std;

int main(int argc, char *argv[])
{
	
	// Animal a;
	// Cow c;

	char a, c;
	a = 'a';
	c = 'c';
	const char *ptr1 = &a;
	const char *ptr2 = &c;
	ptr1 = &c;
	ptr2 = &a;


}