/******************************************************************************************************
* Seyedreza Najafi , March-2018
* Solution to the following problem from the "Cracking the Coding Interview" book, 6th edition
*
* 4.10 Check Subtree
*
******************************************************************************************************/
#include <iostream>
#include <vector>
#include "../utilities/Tree.h"
using namespace std;
template<typename T1, typename T2>
bool operator!=(pair<T1, T2>& p1, pair<T1, T2>& p2)  {
	return ((p1.first != p2.first) || (p1.second != p2.second));
}

class CheckSubTree {
public:
	typedef pair<int, int> NodeVal;

	CheckSubTree() {}
	bool check(Node* t1, Node* t2) {
		preOrder(t1, 0);
		preOrder(t2, 1);
		return match();
	}
	vector<NodeVal>& getTraversal(int id){ return v[id];}
private:
	void preOrder(Node* n, int id) {
		// traverse the tree in pre-order manner, store the node values in the v[id]
		preOrderRec(n, id);
	}
	void preOrderRec(Node* n, int id) {
		if (!n) {
			v[id].push_back(make_pair(-1, 1));
			return;
		}
		v[id].push_back(make_pair(n->v, 0));
		preOrderRec(n->a[0], id);
		preOrderRec(n->a[1], id);
	}
	bool match() {
		// match v[0], v[1], is second one a subsequence of first one?
		for (int i = 0; i < v[0].size() - v[1].size()+1; i++) {
			bool ret = true;
			for (int j = 0; j < v[1].size(); j++) {
				if (v[0][i + j] != v[1][j]) { ret = false; break;  }
			}
			if (ret) return true;
		}
		return false;
	}
	vector<NodeVal> v[2];
};

bool test(Node* t1, Node* t2) {
        CheckSubTree cst;
        bool matched = cst.check(t1,t2);
        cout << (matched? "Matched ":"Not a match")<<endl;
        for(auto& e: cst.getTraversal(0)){
            cout << "( " << e.first <<" , " << e.second <<" )"<< endl;
        }
        cout << endl;
        for(auto& e: cst.getTraversal(1)){
            cout << "( " << e.first <<" , " << e.second <<" )"<< endl;
        }
}
int main() {

    //TODO : write test code
    Node* n3 = ct(3,ct(1),ct(3));
    Node* t1 = ct(3,n3);
    Node* t2 = ct(3,ct(3),ct(3));
    Node* t3 = ct(3,ct(1),ct(3));
    test(t1,t2);
    test(t1,t3);
    
}