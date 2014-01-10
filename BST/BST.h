#ifndef _BST_H_
#define _BST_H_

#include <iostream>
using namespace std;

namespace shafeen {
namespace data_structures {

// Binary Search Tree Data Structure
// This BST is for the <int> type ONLY!
class BST {
public:

	BST();
	virtual ~BST();

	class BST_Node;
	BST_Node *head;

	void insert(int);
	bool exists(int);
	bool removeSingleOccurence(int);
	bool removeAllOccurences(int);
	


};


}
}





#endif /* _BST_H_ */