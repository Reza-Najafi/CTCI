#include "../utilities/Tree.h"
#include <iostream>
#include <queue>
using namespace std;

Node* sum_up(Node* n){
    if(!n) {return NULL;}
    Node* root = new Node(n->v, n->a[0], n->a[1]);
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node* thisN = q.front();
        Node *newl = NULL, *newr = NULL;
        if(thisN->a[0]){ 
            Node* l = thisN->a[0];// on the original tree
            newl = new Node(l->v+thisN->v, l->a[0], l->a[1]);
            q.push(newl);
        }
        if(thisN->a[1]){ 
            Node* r = thisN->a[1];// on the original tree
            newr = new Node(r->v+thisN->v, r->a[0], r->a[1]);
            q.push(newr);
        }
        thisN->a[0] = newl;
        thisN->a[1] = newr;
        q.pop();
    }

    return root;
}


int main() {
    Node* n1 = ct(1,NULL,ct(3));
    Node* n2 = ct(2,ct(1),ct(-1));
    Node* n4 = ct(4,NULL,ct(2));
    Node* n5 = ct(5,ct(-3),NULL);
    Node* n6 = ct(6,n1,n2);
    Node* n_5 = ct(-5,n4,n5);
    Node* root = ct(2,n6,n_5);
    printTree(root);
    Node* sumTree = sum_up(root);
    cout << "Sum Tree\n";
    printTree(sumTree);
}