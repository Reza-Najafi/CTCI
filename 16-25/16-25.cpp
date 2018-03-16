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
    LRU(int max_size):sz(0),maxSize(max_size),head(NULL) { cout << "costructed the list \n"; }
    int size() {return sz;}

    void print(){
        Node* n = head;
        while(n){
            cout <<"( " << n->key << " , " << n->val << " )"<< "  ";
            n = n->next;
        }
        cout << endl;
    }
    bool retrieve(int k, int& val)
    {
        Node* found = find(k);
        if(found == NULL) {return false;}
        val = found->val;
        replaceTheHead(found);
        return true;
    }

    void insert(int key , int val){
        cout << "Inserted the ( "<< key<<" " << val << " )"<< endl;
        // Check if key is already in the list, just replace the value and move the node to be the head
        Node* found = find(key); 
        if(found){
            found->val = val;
            replaceTheHead(found);
            return;
        }
        // if key is not alreay stored and there is still room for it, just create a new node and add it at the front
        if(sz < maxSize){
            createNodeAtFront(key, val);
            return;
        }
        // if key is not there already and there is no more room , remove the tail and add the new node at the front
        removeTail();
        createNodeAtFront(key, val);
    } 

    const int maxSize;
private:

    Node* find(int key){
        if(!head){return NULL;}
        Node* n = head;
        Node* found = NULL;
        while(n){
            if(n->key == key){
                found = n;
                break;
            }
            n = n->next;
        }
        return found;
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
    
    void createNodeAtFront(int key, int val){
        Node* n = new Node();
        n->key = key;
        n->val = val;
        n->next = head;
        head = n;
        sz++;
    }
    
    Node* removeTail(){
        if(!head){return NULL;}
        Node* n = head;
        Node* prev = n;
        while (n->next){ prev = n; n = n->next; }
        delete n;
        prev->next = NULL;
        sz--;
        return prev;
    }
    
    int sz;
    Node* head;
};


#define N 6
int main()
{
    LRU lru(10);
    int key = 1, val;
    for(int i = 1; i < 15; i++){
        lru.insert(i,i*100);
        if(lru.retrieve(key, val)) {
            cout << "found the key "<< key << " its value is "<< val << endl;
        } else {
            cout << "could not find the key "<< key << endl;
        }
    }
    
    int keyList[N] ={14 , 6, 7 ,13 , 12 , 70} ;
    lru.print();
    for(int i = 0; i < N; i++) {
        key = keyList[i];
        if(lru.retrieve(key, val)) {
            cout << "found the key "<< key << " its value is "<< val << endl;
        } else {
            cout << "could not find the key "<< key << endl;
        }
    }
    cout << "Cash state after above accesses\n";
    lru.print();
    return 0;
};