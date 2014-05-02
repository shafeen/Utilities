//
// testing dynamic dispatch for inherited classes
//

#include <iostream>
using namespace std;

class Animal {

public:
	char *name;
	int numLegs;

	Animal()
	{
		name = new char[4+1];
		for(int i = 0; i < 4; i++)
			name[i] = ("none")[i];
		cout << "Animal\tconstructor called\n";
	}

	virtual ~Animal()
	{
		cout << "Animal\tdestructor called.\n";
		delete name;
	}
	
	void printName()
	{
		cout << "name = " << name << endl;
	}

};

class Cat : public Animal {

public:

	Cat()
	{
		cout << "Cat\tconstructor called.\n";
	}

	~Cat()
	{
		cout << "Cat\tdestructor called.\n";
	}
};


class Persian : public Cat {

public:

	Persian()
	{
		cout << "Persian\tconstructor called.\n";
	}

	~Persian()
	{
		cout << "Persian\tdestructor called.\n";
	}
};







int main()
{
	Animal *c = new Persian();
   	delete c;


}