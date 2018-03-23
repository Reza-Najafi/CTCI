/******************************************************************************************************
* Seyedreza Najafi , March-2018
* Solution to the following problem from the "Cracking the Coding Interview" book, 6th edition
* 
* 10.3 Given a sorted array of n integers that has been rotated an unknown
* number of times, write code to find an element in the array. You may assume that the array was
* originally sorted in increasing order.
* EXAMPLE
* Input:find 5 in{15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14}
* Output: 8 (the index of 5 in the array)
******************************************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
int find_in_rotated_array(vector<int>& a, int x){
    int l = 0;
    int h = a.size()-1;
    //TODO probably need to reject if x not within the range
    while(l<=h){
        int mid = (l+h)/2;
        if(a[mid] == x) { return mid; }
        if(a[l]<=a[mid]) { // the linear section is the left half
            if(x<a[mid] && x>=a[l]) { // the target is in this half
                h = mid-1;
            } else {      // the target is not in this half
                l = mid+1;
            }
        } else {          // a[mid] <= a[h] the linear section is the right half
            if(x>a[mid] && x<=a[h]) { // the target is in this half
                l = mid+1;
            } else {      // the target is not in this half
                h = mid-1;
            }
        }
    }
    return -1;
}
int find_the_discontinuity(vector<int>& a){
    int l = 0;
    int h = a.size()-1;
    if(a[0]<=a[h]) {return -1;} 
    while(l<=h){
        int mid = (l+h)/2;
        if(a[mid]>a[mid+1]){
            return mid;
        }
        if(a[l]>a[mid]){
            h = mid;
        } 
        if(a[mid] > a[h]){
            l = mid;    
        }
    }
    return l;
} 

void dtest(vector<int>& a){
    cout << endl << endl;
    cout << "The input array is \n";
    for(auto&& e:a){
        cout << e<<" , ";
    }
    cout <<endl<< "Discontinuity idx "<< find_the_discontinuity(a) << endl;
}
void test(vector<int>& a, int target){
    cout <<"Target : "<< target<<" is at idx "<< find_in_rotated_array(a, target) << endl;  
}

int main()
{
    vector<int> a = {15, 16, 19, 20, 25, 26, 1, 3, 4, 5, 7, 10, 14};
    dtest(a);
    test(a,26);
    test(a,27);
    test(a,0);
    
    vector<int> b = {15, 1, 3, 4, 5, 7, 10, 14};
    dtest(b);
    test(b,1);
    
    vector<int> c = {15, 16, 19, 20, 25, 26, 1};
    dtest(c);
    test(c,1);
    
    vector<int> d = {15, 16, 19, 20, 25, 26};
    dtest(d);
    test(d,26);
    
    vector<int> e = {15, 15, 15, 16, 19, 20, 25, 26, 26, 1, 1, 3, 3, 4, 4, 4};
    dtest(e);
    test(e,26);
    test(e,24);
}


