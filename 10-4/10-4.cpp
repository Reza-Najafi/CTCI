#include <iostream>
using namespace std;
/*
* Seyedreza Najafi , March-2018
* 
* 10.4 Sorted Search, No Size: You are given an array-like data structure Listy which lacks a size
* method. It does, however, have an elementAt (i) method that returns the element at index i in
* O(1) time. If i is beyond the bounds of the data structure, it returns -1. (For this reason, the data
* structure only supports positive integers.) Given a Li sty which contains sorted, positive integers,
* find the index at which an element x occurs. If x occurs multiple times, you may return any index.
*
*/


/*
* The Listy class initializes an array of the size passed to the constructor
* it gives access to its elements through the [] operator and also can be used 
* with range based for loops as begin() and end() has been imlemented for it.
*/
class Listy {
    public:
    Listy(int size):sz(size){
        a = new int[size];
        for (int i = 0; i < size; i++){
            a[i] = 2*i;
        }
    }
    int elementAt(int i) {
        if(i < sz){
            return a[i];
        }
        return -1;
    }
    int operator[](int i){
        return elementAt(i);
    }
    ~Listy(){ delete [] a;}
    int* begin() {return a;};
    int* end() {return a+sz;};
    private:
    int* a ;
    const int sz;
};

pair<int, int> findFirstGreatorVal(Listy& a, int offset, int x){
    if(a[offset] != -1 && a[offset+1] == -1) { return make_pair(-1,-1); }// The last element
    // check if the start is an element bigger than the x
    if(x<=a[offset]){
        return make_pair(offset,offset);
    }    
    // start looking at 2^i distances from the offset until 
    // finding an element that is bigger than x, 
    int lastTriedLoc = offset;
    for(int i = 0; ; i++){
        int newIdx = offset + (1 << i);
        if(a[newIdx] == -1) {
            break;
        }
        if( x <= a[newIdx]) {
            // if found the element bigger than the x return its index and
            // the index of the previous looked up location
            return make_pair( lastTriedLoc , newIdx);
        }
        lastTriedLoc = newIdx;
    }
    // if got out of range (-1 is returned) call the same 
    // function at the previous location that was not out of range
    return(findFirstGreatorVal(a,lastTriedLoc, x));
}

int find(Listy& a, int x)
{
    auto p = findFirstGreatorVal(a,0,x);
    // Perform a binary search between p.first and p.second
    int l = p.first;
    int h = p.second;
    if(l<0 || h<0) {return -1;}
    while(l<=h){
        int m = (l+h)/2;
        if(a[m] == x){return m;}
        if(x<a[m]){h=m-1;}
        if(x>a[m]){l=m+1;}
    }
    return -1;
}

int main() {
    Listy a(15);
    cout << "Input array :"<<endl;
    for(auto&& e:a){
        cout << e << " , ";
    }
    int target = 25;
    auto p = findFirstGreatorVal(a,0,target);
    cout << endl <<"The target: "<<target<< " is located in: [ "<< p.first << " "<< p.second<< " ] "<<endl;
    
    cout << "The index which the target is located at is "<< find(a,target)<<endl;
}



