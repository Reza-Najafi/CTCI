/******************************************************************************************************
* Seyedreza Najafi , March-2018
* Solution to the following problem from the "Cracking the Coding Interview" book, 6th edition
* 
* 4-3 List of Depths
*
******************************************************************************************************/
#include<vector> 
#include<list>
#include<queue>
#include <iostream>
#include "../utilities/Tree.h"
using namespace std;
// Do a BFS
// Wrap the nodes in a wrapper to keep the level info
// Push stuff into a list, when level changes, push the created list into the vector, create a new list 
// return the vector

struct Wrapper {
	Wrapper(Node* node, int level) :n(node), lvl(level) {}
	Node* n;
	int lvl;
};

vector<list<int>> getLevelLists(Node* n) {
	queue<Wrapper> q;
	q.push(Wrapper(n, 0));
	int currLevel = -1;
	vector<list<int>> v;
	while (!q.empty()) {
		Wrapper & thisNode = q.front();
		// started traversing a new level
		if (currLevel != thisNode.lvl) {
			currLevel = thisNode.lvl;
			list<int> lst;
			lst.push_back(thisNode.n->v);
			v.push_back(lst);
		}
		else {
			v.back().push_back(thisNode.n->v);
		}
		if(thisNode.n->a[0])q.push(Wrapper(thisNode.n->a[0], thisNode.lvl + 1));
		if(thisNode.n->a[1])q.push(Wrapper(thisNode.n->a[1], thisNode.lvl + 1));
		q.pop();
	}
	return v;
}

int main(){
    Node* n6 = ct(6,ct(0));
    Node* n5 = ct(5,ct(3), n6);
    Node* n4 = ct(4,ct(2),n5);
    auto v = getLevelLists(n4);

    for(auto&& l:v) {
        cout << endl;
        for(auto&& e:l) { cout << e << " "; }
        cout << endl;
    }
}