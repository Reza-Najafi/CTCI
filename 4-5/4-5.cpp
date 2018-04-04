/******************************************************************************************************
* Seyedreza Najafi , March-2018
* Solution to the following problem from the "Cracking the Coding Interview" book, 6th edition
* 
* 4.5 Validate BST
*
******************************************************************************************************/
#include <iostream>
#include "../utilities/Tree.h"
using namespace std;
#if 0
struct Node {
	int v;
	Node* r = NULL;
	Node* l = NULL;

	Node(int val) { v = val; r = NULL; l = NULL; }
};
Node* ct(int v, Node* l = NULL, Node* r = NULL) {
	Node* ret = new Node(v);
    ret->l = l;
    ret->r = r;
	return ret;
}
#endif
class ValidateBST {
public:
	bool validate(Node* n) {
		if (!n) { return false; }
		ret = true;
		validateRec(n);
		return ret;
	}
private:
	void validateRec(Node* n) {
		if (!n || !ret) { return; }
		validateRec(n->a[0]);
		if (n->a[0]) {
			if (n->v < n->a[0]->v) 	{
				ret = false; return;
			}
		}
		if (n->a[1]) {
			if (n->v > n->a[1]->v) {
				ret = false; return;
			}	
		}
		validateRec(n->a[1]);
	}

	int last;
	bool ret;
};

int main() {
	ValidateBST vbst;
	Node* test;

    Node* n13 = ct(13);
    Node* n15 = ct(15);
    Node* n14 = ct(14,n13,n15);
    Node* n12 = ct(12,NULL,n14);
    Node* n11 = ct(11,NULL,n12);
    Node* n16 = ct(16,n11);
    Node* n10 = ct(10,NULL,n16);
    test = n10;

	printTree(test);
    cout << (vbst.validate(test)?"Is BST":"Not a BST")<<endl;

	Node* n3 = ct(3,ct(1),ct(0));
	test = n3;
	printTree(test);
    cout << (vbst.validate(test)?"Is BST":"Not a BST")<<endl;
}