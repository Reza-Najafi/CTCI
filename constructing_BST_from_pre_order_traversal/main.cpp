#include <iostream>
#include <vector>
#include "utilities/Tree.h"

using namespace std;

Node* processHist(vector<Node*>& hist, int newItem) {
    int i = 0;
    Node* found = NULL;
    for(;i<hist.size(); i++) {
        if(newItem>=hist[i]->v) {
            if(!found) {
                found = hist[i];
                break;
            }
        }
    }
    if(found) {
        hist.erase(hist.begin()+i,hist.end());
    }
    return found;
}


void recBuild(vector<int>& v, int id, vector<Node*>& hist, Node* curNode){
    if(!curNode) return ;
    if(id >= v.size()) return;
    auto curItem = v[id];
    auto newNode = new Node(curItem);
    if(curItem < curNode->v) {
        curNode->addLeft(newNode);
    } else {
        Node* largerNode = processHist(hist,curItem);
        largerNode->addRight(newNode);
    }
    hist.push_back(newNode);
    recBuild(v,id+1,hist,newNode);
}


Node* buildTree(vector<int>& v) {
    if(v.size() == 0) {return NULL;}
    auto root = new Node(v[0]);
    vector<Node*> hist = {root};
    recBuild(v,1,hist,root);
    return root;
}

int main() {
    vector<int> v = {10,18,13,15,14,16,20};
    auto tree = buildTree(v);
    printTree(tree);
}
