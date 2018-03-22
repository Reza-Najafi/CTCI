#include "../utilities/Tree.h"
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

Node* create_sum_up_tree(Node* n) {
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


int count_node_with_sum(Node* n, int sum) {
    if(!n) {return 0;}
    return ((n->v == sum)+count_node_with_sum(n->a[0],sum)+count_node_with_sum(n->a[1], sum));
}


int count_path_with_sum(Node* n, vector<int>& v, int sum) {
    if(!n) {return 0;}
    int ret = (n->v == sum);
    for(auto& parentNodeSum :v){
        if((n->v - parentNodeSum)==sum) {
            ret++;
        }
    }
    v.push_back(n->v);
    ret += count_path_with_sum(n->a[0],v, sum);
    ret += count_path_with_sum(n->a[1],v, sum);
    v.pop_back();
    return ret;
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
    Node* sumTree = create_sum_up_tree(root);
    cout << "Sum Tree\n";
    printTree(sumTree);
    int sum = 9;
    vector<int> v;
    cout << "Number of path with size "<< sum << " : "<<count_path_with_sum(sumTree,v, sum) << endl;
    
}
