//
// testing compression algorithms
//

#include <iostream>
using namespace std;


char getCharInput(const char *msg = "Enter a number from 0-255: ")
{
	cout << msg << endl;
	unsigned int n;
	cin >> n;
	return (char)n;
}


int main()
{
	while(1)
	{
		cout << getCharInput() << endl ;
	}


}