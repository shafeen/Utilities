#ifndef _BST_H_
#define _BST_H_

#include <iostream>
using namespace std;

namespace shafeen {
namespace data_structures {

// Binary Search Tree Data Structure
// This BST is for the <int> type ONLY!
template <class T>
class BST {
public:

	BST();
	virtual ~BST();

	class BST_Node;
	BST_Node *head;

	void insert(T);
	bool exists(T);
	bool removeSingleOccurence(T);
	bool removeAllOccurences(T);
	


};


}
}





#endif /* _BST_H_ */