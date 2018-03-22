#include "../utilities/Tree.h"
#include <iostream>
using namespace std;
int main() {
    Node* n1 = ct(1,NULL,ct(3));
    Node* n2 = ct(2,ct(1),ct(-1));
    Node* n4 = ct(4,NULL,ct(2));
    Node* n5 = ct(5,ct(-3),NULL);
    Node* n6 = ct(6,n1,n2);
    Node* n_5 = ct(-5,n4,n5);
    Node* root = ct(2,n6,n_5);
    cout << n->v;
}