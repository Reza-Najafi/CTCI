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
bool operator=(pair<T1, T2> p1, pair<t1, T2> p2) {
	return ((p1.first = p2.first) && (p1.second == p2.second));
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
private:
	void preOrder(Node* n, int id) {
		// traverse the tree in pre-order manner, store the node values in the v[id]
		preOrderRec(n, id);
	}
	void preOrderRec(Node* n, int id) {
		if (!n) {
			v[id].push_pack(make_pair<0, 1>);
			return;
		}
		v[id].push_pack(make_pair<n->v, 0>);
		preOrderRec(n->a[0], id);
		preOrderRec(n->a[1], id);
	}
	bool match() {
		// match v[0], v[1], is second one a subsequence of first one?
		for (int i = 0; i < v[0].size() - v[1].size(); i++) {
			bool ret = true;
			for (int j = 0; j < v[1].size(); j++) {
				if (v[0][i + j] != v[1][j]) { break; ret = false; }
			}
			if (ret) return true;
		}
		return false;
	}
	vector<NodeVal> v[2];
};