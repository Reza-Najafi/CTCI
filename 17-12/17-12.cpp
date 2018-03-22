#include <iostream>
#include "../utilities/Tree.h"
using namespace std;



Node* rec(Node*n , int p) {

    Node* l = NULL, *r = NULL;
    if(n->a[0]) {
        l = rec(n->a[0],0);
    }
    if(n->a[1]) {
        r = rec(n->a[1],1);
    }
    Node* ret = NULL;
    n->a[1] = r;
    n->a[0] = l;
    if(l)l->a[1] = n;
    if(r)r->a[0] = n;
    if(p==0){
        if(r) {
            ret = r;
            // continue on the right wing until the leaf
            while(ret->a[1]){
                ret = ret->a[1];
            }
        } else {
            ret = n;
        }
    }

    if(p==1){
        if(l) {
            ret = l;
            // continue on the left wing until the leaf
            while(ret->a[0]){
                ret = ret->a[0];
            }
        } else {
            ret = n;
        }
    }

    return ret;
}
Node* straigten(Node* n){
    rec(n,1);
    while(n->a[0]){n= n->a[0];}
    return n;
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
    Node* res = straigten(tree_root);
    do{
        cout << res->v << " , ";
        res=res->a[1];
    }while(res);


    return 0;
}
