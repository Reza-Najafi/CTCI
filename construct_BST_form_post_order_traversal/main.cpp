#include <iostream>
#include "utilities/Tree.h"
using namespace std;


int partition(vector<int>& v, int l, int r){
    int p = v[r];
    int ret = l-1;
    for(int i = r-1; i >=l ; i--) {
        if(v[i]<=p) {
            ret = i;
            break;
        }
    }
    return ret;
}
Node* buildTree(vector<int>& v, int l, int r) {
    if(l < 0 || l > r) return NULL;
    auto newRoot = new Node(v[r]);
    if(l==r) return newRoot;
    auto mid = partition(v,l,r);
    newRoot->addLeft(buildTree(v,l,mid));
    newRoot->addRight(buildTree(v,mid+1,r-1));
    return newRoot;
}

int main() {
    vector<int> v = {14,16,15,13,20,18,10};
    auto tree = buildTree(v,0,v.size()-1);
    printTree(tree);
}
