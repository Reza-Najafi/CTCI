#include <iostream>
#include "../utilities/Tree.h"

using namespace std;

/*
* The rec function converts a subtree into a doubly likned list and 
* returns a pair of pointers first to the head second to the tail
*/
pair<Node*,Node*> rec(Node*n , int p) {
    Node *n1 = NULL;
    pair<Node*,Node*> l = make_pair(n1,n1);
    pair<Node*,Node*> r = make_pair(n1,n1);
    
    // Run the same routine on the left and right subtrees and get two lists l,r
    if(n->a[0]) {
        l = rec(n->a[0],0);  
    }
    if(n->a[1]) {
        r = rec(n->a[1],1);  
    }
    
    // Merge the two resulting lists (l,r) and the current node into a new list
    n->a[1] = r.first;
    n->a[0] = l.first;
    if(l.first)(l.first)->a[1] = n;
    if(r.first)(r.first)->a[0] = n;
    
    // Putting together the return pair
    pair<Node*,Node*> ret = make_pair(n1,n1);
    ret.first = n;
    ret.second = n;
    if(p==0){
        if(r.second) { ret.first = r.second; }
        if(l.second) { ret.second = l.second; } 
    }
        
    if(p==1){
        if(l.second) { ret.first = l.second; }
        if(r.second) { ret.second = r.second; }
    }
 
    return ret;
}
pair<Node*,Node*> straigten(Node* n){
    return rec(n,1);
};



int main()
{
    #if 1
    Node* n3 = ct(3, ct(2,ct(1)), ct(4));
    Node* n6 = ct(6,nullptr,ct(7));
    Node* n8 = ct(8,n6);
    Node* n12 = ct(12,ct(11,ct(10)),ct(13));
    Node* n14 = ct(14,n12,ct(20));
    Node* n13 = ct(13,nullptr, n14);
    Node* n9  = ct(9,n8,n13);
    Node* n  = ct(5,n3,n9);
    #endif
    Node* tree_root = n;
    printTree(tree_root);
    auto p = straigten(tree_root);

    cout << "Traversing from the head to tail"<<endl;
    Node* res = p.first; // list head
    do{
        cout << res->v << " , ";
        res=res->a[1];
    }while(res);
    
    cout << "Traversing from the tail to head"<< endl;
    res = p.second; // list head
    do{
        cout << res->v << " , ";
        res=res->a[0];
    }while(res);
    
    return 0;
}






