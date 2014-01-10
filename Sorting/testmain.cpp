
#include <iostream>
#include <vector>
#include <cstdlib>
#include "Quicksort.cpp"

using namespace std;

void printVector(std::vector<int> &v)
{
	int size = v.size();
	for(int i = 0; i < size; i++)
		cout << v[i] << endl;
	cout << endl;
}

int main(int argc, char *argv[])
{	

	std::vector<int> v;
	for(int i = 0; i < 100; i++)
		v.push_back(rand() % 100);
	
	printVector(v);	

	Quicksort(v);
	// printVector(v);





}