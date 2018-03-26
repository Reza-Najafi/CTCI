/******************************************************************************************************
* Seyedreza Najafi , March-2018
* Solution to the following problem from the "Cracking the Coding Interview" book, 6th edition
* 
* 4.4 Check Ballanced
*
******************************************************************************************************/
#include <iostream>
#include <math.h>
#include "../utilities/Tree.h"
using namespace std;
// Find the left subtrees height
// find the right subtree's height
// set this node's height based on left/right


class IsBallanced {
public:
	bool check(Node* n) {
		ret = true;
		checkRec(n);
		return ret;
	}
private:
	void checkRec(Node* n) {
		if (!ret) { return; }
		if (n->a[0]) {
			checkRec(n->a[0]);
			n->lh = max(n->a[0]->lh, n->a[0]->rh) + 1;
		}
		else { n->lh = 0; }
		if (n->a[1]) {
			checkRec(n->a[1]);
			n->rh = max(n->a[1]->lh, n->a[1]->rh) + 1;
		}
		else { n->rh = 0; }
		ret = ret && (n->rh == n->lh-1 || n->rh-1 == n->lh || n->rh == n->lh);
	}
	bool ret;
};

int main(){
    Node* n6 = ct(6,ct(0));
    Node* n5 = ct(5,ct(3), n6);
    Node* n4 = ct(4,ct(2),n5);
    IsBallanced isBallanced;
    printTree(n4);
    cout << "Is " <<( isBallanced.check(n4)?"Ballaned":"Not ballanced" )<<endl; 
    printTree(n5);
    cout << "Is " <<( isBallanced.check(n5)?"Ballaned":"Not ballanced" )<<endl; 
    
}