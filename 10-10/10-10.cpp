/******************************************************************************************************
* Seyedreza Najafi , March-2018
* Solution to the following problem from the "Cracking the Coding Interview" book, 6th edition
* 
* 10.10 Rank from Stream
*
******************************************************************************************************/
#include <iostream>

class RankFromStream {
public:
	struct Node {
		int v;
		int lCount;
		int rCount;
		Node* r;
		Node* l;
		Node() :r(NULL), l(NULL), lCount(0), rCount(0) {}
		Node(int val) :v(val), r(NULL), l(NULL), lCount(0), rCount(0) {}
		Node(int val, Node* right, Node* left) :v(val), r(right), l(left), lCount(0), rCount(0) {
			setRight(right);
			setLeft(left);
		}
		void setRight(Node* right) {
			if (right) { rCount = right->rCount + right->lCount + 1; }
			r = right;
		}
		void setLeft(Node* left) {
			if (left) { lCount = left->rCount + left->lCount + 1; }
			l = left;
		}
	};
	RankFromStream() :root(NULL) {}
	void track(int v)
	{
		// create a new node
		Node* n = new Node(v);
		Node* thisN = root;
		if (!thisN) {
			root = n;
			return;
		}

		while (thisN) {
			if (v < thisN->v) {
				if (!thisN->l) {
					thisN->setLeft(n);
					return;
				}
				thisN->lCount++;
				thisN = thisN->l;
			}
			else if (v > thisN->v) {
				if (!thisN->r) {
					thisN->setRight(n);
					return;
				}
				thisN->rCount++;
				thisN = thisN->r;
			}
			else {
				Node* leftSubTree = thisN->l;
				n->setLeft(leftSubTree);
				thisN->setLeft(n);
				return;
			}
		}
	}
	int getRankOfNumber(int v) {
		// lookup the number or the subtree that it would end up
		Node* thisN = root;
		int count = 0;
		if (!thisN) {
			return count;
		}

		while (thisN) {
			if (v < thisN->v) {
				if (!thisN->l) {
					return count;
				}
				thisN = thisN->l;
			}
			else if (v > thisN->v) {
				if (!thisN->r) {
					return (count + thisN->lCount + 1);
				}
				count += thisN->lCount + 1;
				thisN = thisN->r;
			}
			else {
				return (count + thisN->lCount);
			}
		}
	}
	~RankFromStream() {
	    //TODO : Do post order traversal and delete all nodes
	}
private:
	Node* root;
};
#include <algorithm>
using namespace std;
int main() {
    int stream[] = {45,10,3,5,8,18,2,3,7,9,1,19,4,7,0,2,12,7,17,18,27,43};
    //int stream[] = {6,1,3};
    RankFromStream rfs;
    for(auto& e: stream) {
        rfs.track(e);
    }
    std::sort(stream, stream+sizeof(stream)/sizeof(stream[0]));
    cout << "Sorted input stream of size "<< sizeof(stream)/sizeof(stream[0]) << endl;
    for(auto& e: stream) {
        cout << e << " , ";
    }
    cout << endl;
    int test[] = {1,2,3,4,7, 0 ,-1, 20, 45, 44, 1000};
    for(auto& e: test) {
        cout << "Rank of " << e << " is " << rfs.getRankOfNumber(e)<< endl;
    }
}