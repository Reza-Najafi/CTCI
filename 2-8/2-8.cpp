#include <iostream>
using namespace std;

struct Node {
    Node* next;
    int val;
    Node(int v):val(v),next(NULL) {};
    Node():next(NULL){};
    Node(int v, Node* nex):val(v),next(nex){};
};

void print(Node* n){
    while(n){
        cout << n->val << " , ";
        n = n->next;
    }
    cout << endl;
}


int main()
{
    Node* head = new Node(0);
    Node* tail = head;
    const int STRAIGHT_PART = 9;
    const int TOTAL_LENGTH = 32;
    for(int i = 1; i <= STRAIGHT_PART; i++){
        Node* n = new Node(i);
        tail->next = n;
        tail = n;
    }
    Node* joint = tail;
    for(int i = STRAIGHT_PART; i < TOTAL_LENGTH; i++){
        Node* n = new Node(i);
        tail->next = n;
        tail = n;
    }
    tail->next = joint;
    //cout << "Initial list: "<< endl;
    //print(head);// DO NOT TRY PRINITING THE BOGOUS LINKED LIST! LOL
    // Finding the colliding location in the loop
    Node* n1 = head, *n2= head;
    do {
        n1 = n1->next;
        if(n2->next){
            n2 = n2->next->next;
        } else {
            break;
        }
    }
    while(n1 != n2 && n1 && n2);

    if(n1 == n2) {
        cout << "Colliding node's value "<< n1->val<< endl;
    } else {
        cout << "There is no loop in this linked list!"<< endl;
        return -1;
    }
    n1 = head;
    while(n1 != n2 ) {
        n1 = n1->next;
        n2 = n2->next;
    }
    cout << "Loop start node's value is "<< n1->val << endl;

}
