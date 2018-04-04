
#include <iostream>
using namespace std;
// 1- check for the right node return if found
// 2- go up the tree , is the current node is the left child of it sparent? return the parent, if not go up the tree, if there is no parent, terminate
struct Node {
    int v;
    Node* r= NULL;
    Node* l = NULL;
    Node* p = NULL;
    Node(int val){ v = val;r = NULL; l = NULL; p = NULL;}
};

Node* ct(int v, Node* l=NULL, Node* r=NULL) {
    Node* ret = new Node(v);
    if(l){
        ret->l = l;
        l->p = ret; 
    }
    if(r){
        ret->r = r;
        r->p = ret; 
    }
    return ret;
}

class FindSuccessor {
    Node* successor = NULL;
    void find_successor(Node* n) {
    	if(successor){return;}
    	Node *p = n->p;
    	if(!p) return;
    	if(p->l == n) {successor = p; return;}
        find_successor(p);
    }
    public:
    Node* find(Node* n){
        successor = NULL;
        if(n->r) { 
            successor = n->r; 
            while(successor->l) {successor = successor->l;}
            return successor;
        } 
        find_successor(n); 
        return successor;}
};


int main() {
    Node* n0 = ct(0);cout << n0 << endl;
    Node* n1 = ct(1);cout << n1 << endl;
    Node* n2 = ct(2,n1,n0);cout << n2 << endl;
    Node* n3 = ct(3,NULL,n2);cout << n3 << endl;
    Node* n4 = ct(4,NULL,n3);cout << n4 << endl;
    Node* n5 = ct(5,n4);cout << n5 << endl;
    Node* n6 = ct(6,NULL,n5);cout << n6 << endl;
    Node* test;
    FindSuccessor fs;
    
    test = n0; cout << "successor of "<< test << " is "<<fs.find(test)<< endl;
    test = n1; cout << "successor of "<< test << " is "<<fs.find(test)<< endl;
    test = n2; cout << "successor of "<< test << " is "<<fs.find(test)<< endl;
    test = n3; cout << "successor of "<< test << " is "<<fs.find(test)<< endl;
    test = n5; cout << "successor of "<< test << " is "<<fs.find(test)<< endl;
}