#include <iostream>
#include <set>
using namespace std;
struct Node {
    Node():next(NULL){}
    int key;
    int val;
    Node* next;
};

class LRU {
public:
    LRU(int max_size):sz(0),maxSize(max_size),head(NULL){cout << "costructed the list \n";}
    int size() {return sz;}

    void print(){
        Node* n = head;
        while(n){
            cout <<"( " << n->val << " , " << n->key << " )"<< "  ";
            n = n->next;
        }
        cout << endl;
    }
    bool retrieve(int k, int& val)
    {
        Node* n = head;
        Node* found = NULL;
        while(n){
            if (n++->key == k) {
                found = n;
                break;
            }
        }
        if(found == NULL) {return false;}
        replaceTheHead(n);
        val = found->val;
        return true;
    }
    void replaceTheHead(Node* n){
        if(n==head) {return;}
        Node* currNode = head;
        while(currNode && currNode->next != n){
            currNode = currNode->next;
        }
        //currNode points to the node before the n
        currNode->next = n->next;
        n->next = head;
        head = n;
    }
    void insert(int key , int val){
        cout << "Inserted the ( "<< key<<" " << val << " )"<< endl;
        // Check if key is already in the list
        Node* n = head;
        Node* found = NULL;
        while(n){
            if(n->val == key){
                found = n;
                break;
            }
            n = n->next;
        }
        if(found){
            found->val = val;
            return;
        }
        // Already full
        if(sz == maxSize) {
            Node* n = head;
            while(n->next) {n = n->next; }
            n->val = val;
            n->key = key;
            return;
        }
        // still has room
        n = new Node();
        n->key = key;
        n->val = val;
        if(!head){
            head = n;
        } else {
            Node* currNode = head;
            while(currNode->next) { currNode  = currNode->next; }
            currNode->next = n;
        }
        sz++;
    }

    const int maxSize;
private:
    int sz;
    Node* head;
};



int main()
{
    LRU lru(10);

    for(int i = 1; i < 15; i++){
        lru.insert(i,i*100);
    }

    lru.print();




    return 0;
}
