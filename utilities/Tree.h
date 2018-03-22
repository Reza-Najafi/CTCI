#include <string>
#include <iostream>
#include <queue>
struct Node{
    int v;
    Node* a[2] = {NULL};
    Node(int val) {v =val;}
    Node(int val, Node* n0=NULL, Node* n1=NULL) {a[0] = n0; a[1]=n1; v = val;}
};
// create_tree function
Node* ct(int v, Node* nl=NULL, Node* nr=NULL) {
    Node* n = new Node(v, nl, nr);
    return n;
};

struct NodeWrapper  {
    Node* n;
    int l;// keeps the level
    int p;//at what location (with respect to the left of the window) did the parent were appear on the screen
    int lr;// left child or right child -1 or 1
    NodeWrapper(Node* node, int level, int pos, int left_right) :n(node),l(level),p(pos),lr(left_right) {}
};

void printTree(Node* n) {
    int curr_level = 0;
    std::queue<NodeWrapper> s;
    int rootWidth = 4*20;
    s.push(NodeWrapper(n,0,rootWidth,0));
    int currLocationOnlevel = 0;
    char delim = '.';
    while(!s.empty()) {
        NodeWrapper thisN = s.front();
        int new_level = thisN.l;
        if(new_level != curr_level){
            curr_level = new_level;
            int remaining =2*rootWidth - currLocationOnlevel;
            if(remaining>0)std::cout << std::string(remaining,delim);
            std::cout << std::endl;
            currLocationOnlevel= 0;
        }
        int children_gap = rootWidth/(1 << (thisN.l));
        int thisLoc = thisN.p+thisN.lr*children_gap - currLocationOnlevel;
        if (thisLoc < 0) {thisLoc = 1;}
        currLocationOnlevel += thisLoc;
        std::cout << std::string(thisLoc,delim) << thisN.n->v ;
        if(thisN.n->a[0]) {
            s.push(NodeWrapper(thisN.n->a[0],thisN.l+1,currLocationOnlevel,-1));
        }
        if(thisN.n->a[1]){
            s.push(NodeWrapper(thisN.n->a[1],thisN.l+1,currLocationOnlevel,1));
        }
        s.pop();
    }
    int remaining =2*rootWidth - currLocationOnlevel;
    if(remaining>0)std::cout << std::string(remaining,delim);
    std::cout << std::endl;
}
