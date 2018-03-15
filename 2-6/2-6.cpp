#include <iostream>
using namespace std;

struct Node {
    Node* next;
    int val;
    Node(int v):val(v),next(NULL) {};
    Node():next(NULL){};
    Node(int v, Node* nex):val(v),next(nex){};
};

void reverse(Node* n, Node* &h) {
    if(!n){
        return;    
    }
    Node* newHead = new Node();
    newHead->val = n->val;
    Node* prevHead = h;
    h = newHead;
    h->next = prevHead;
    reverse(n->next,h);
}

void print(Node* n){
    while(n){
        cout << n->val << " , ";
        n = n->next;
    }
    cout << endl;
}

bool compare(Node* n, Node* m) {
    while(n || m) {
        if(!n) {return false;}
        if(!m) {return false;}
        if(n->val != m->val){return false;}
        n = n->next;
        m = m->next;
    }
    return true;
}
int main()
{
    Node* head = new Node(0);
    Node* tail = head;
    for(int i = 1; i < 10; i++){
        Node* n = new Node(i);
        tail->next = n;
        tail = n;
    }
    for(int i = 10; i >=0; i--){
        Node* n = new Node(i);
        tail->next = n;
        tail = n;
    }
    cout << "Initial list: "<< endl;
    print(head);
    Node * rHead = NULL;
    reverse(head,rHead);
    cout << "Reversed list: "<< endl;
    print(rHead);
    cout << (compare(rHead, head) ? "Is a palindrome":"Not a palindrom")<<endl;
}
