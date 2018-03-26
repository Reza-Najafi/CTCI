/******************************************************************************************************
* Seyedreza Najafi , March-2018
* Solution to the following problem from the "Cracking the Coding Interview" book, 6th edition
* 
* 4-2 Minimal Tree
*
******************************************************************************************************/
#include <iostream>
#include "../utilities/Tree.h"
using namespace std;
Node* createMinimalTree(int* arr, int l, int h) {
	if(l>h) {return NULL;}
	int mid = (l+h)/2;
	Node* n = new Node(arr[mid]);
	n->a[0] = createMinimalTree(arr, l,mid-1);
	n->a[1] = createMinimalTree(arr, mid+1,h);
	return n;
}
int main() {
    int arr[] = {1,2,5,6,9,17,37,60,69,89,100,104,156,200,209,219,235,350};
	for(auto& e:arr){cout << e << " "; }
	cout << endl;
    Node* root = createMinimalTree(arr, 0, sizeof(arr)/sizeof(arr[0]));
    printTree(root);
	int arr2[] = {1,5,9,15, 20, 26, 50};
	for(auto& e:arr2){cout << e << " "; }
	cout << endl;
	Node* root2 = createMinimalTree(arr2,0, sizeof(arr2)/sizeof(arr2[0]));
	printTree(root2);
}
