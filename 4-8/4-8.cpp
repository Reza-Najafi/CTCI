#include <iostream>
#include "utilities/Tree.h"
using namespace std;
class FirstCommonAncestor {
public:
	Node* dca = NULL;
	// Finds the first common ancestor
	int set_fca(Node* n, pair<Node*, Node*> np) {
		if (dca) { return 0; }
		if (!n) { return 0; }
		int left_res = set_fca(n->a[0], np);
		int right_res = set_fca(n->a[1], np);
		if (left_res == 1 && right_res == 1) { dca = n; return 0; }
		if ((left_res == 1 || right_res == 1) && (n == np.first || n == np.second)) { dca = n; return 0; }
		return (((n == np.first || n == np.second) ? 1 : 0) + left_res + right_res);
	}

};


int main() {
	Node* n1 = ct(1);
	Node* n4 = ct(4);
	Node* n2 = ct(2);
	Node* n3 = ct(3, n1, n2);
	Node* n6 = ct(6, ct(7), n4);

	Node* n5 = ct(5, n3, n6);
	Node* n11 = ct(11);
	Node* n9 = ct(9, ct(10), n11);
	Node* root = ct(8, n5, n9);
	printTree(root);
	FirstCommonAncestor fca;
	fca.set_fca(root, make_pair(n6, n1));
	cout << fca.dca << endl;
	cout << n5 << endl;
}