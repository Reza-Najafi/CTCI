/******************************************************************************************************
* Seyedreza Najafi , March-2018
* Solution to the following problem from the "Cracking the Coding Interview" book, 6th edition
* 
* 2.5 Sum Lists
*
******************************************************************************************************/
#include <iostream> 
using namespace std;
struct Node {
    int val;
    Node *next;
    Node(int x) : val(x), next(NULL) {}
};

class SumLists {
    int c;
    void addDigits(Node* l1, Node* l2, Node*& n){
        if(!l1 && !l2 ) {
           if(c!=0) { n = new Node(c); }
           return;
        }
        int a = (l1) ? l1->val:0;
        int b = (l2) ? l2->val:0;
        int res = a+b+c;
        n = new Node(res%10);
        c = (res >= 10) ? 1:0;
        addDigits(l1 ? l1->next: NULL, l2 ? l2->next : NULL, n->next);
    }
public:
    Node* addTwoNumbers(Node* l1, Node* l2) {
        // keep adding nodes and push the pointers ahead plus keep a carry on 
        // do until no pointer can go ahead
        Node* h = NULL;
        c = 0;
        addDigits(l1,l2,h);
        return h;
    }
};
int main() {
    Node* n1 = new Node(0);
    Node* m1 = new Node(1);
    Node* m2 = new Node(8);
    m1->next = m2;
    SumLists sl;
    Node* a = sl.addTwoNumbers(n1,m1);
    while(a){
        cout << a->val << " ";
        a = a->next;
    }
}