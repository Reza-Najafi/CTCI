/******************************************************************************************************
* Seyedreza Najafi , March-2018
* Solution to the following problem from the "Cracking the Coding Interview" book, 6th edition
* 
* 10.1 Sorted Merge
*
******************************************************************************************************/
#include <iostream>
using namespace std;

template<size_t A,size_t B>
void merge_arrays(int (&a)[A], int(&b)[B]){
    if(A==0 || B==0) {return; }
    int* pa = a+A-1;// read pointer for a
    int* pb = b+B-1;// read pointer for b
    while(pa>=a && *pa == 0){
        pa -= 1;
    }

    int* w= a+A;// write pointer
    while(--w >=a && (pb>=b || pa >=a)) {
        if(pa >=a && pb >= b) {
            if(*pa>*pb) {
                *w = *pa;    
                pa--;
            } else {
                *w = *pb;
                pb--;
            }
        }
        else if(pa >=a && pb < b) 
        {
            return;
        } 
        else if(pa < a && pb >= b) 
        {
            *w = *pb;
            pb--;
        }
    }
}

template<size_t A, size_t B>
void test(int (&a)[A], int (&b)[B]) {
    cout << "Array a:\n";
    for(auto&& i : a){
        cout << i << " , ";
    } 
    cout << endl << "Array b:\n";
    for(auto&& i : b){
        cout << i << " , ";
    } 
    merge_arrays(a,b);
    cout << endl << "Array a after merge :\n";
    for(auto&& i : a){
        cout << i << " , ";
    } 
    cout << endl;
    cout << endl;
}

int main()
{
    #if 1
    int a[] = {1,15,16,27,37,0,0,0};
    int b[] = {10,20,30};
    test(a,b);
    
    int c[] = {0,0,0};
    int d[] = {10,20,30};
    test(c,d);

    int e[] = {1,15,16,27,37};
    int f[] = {-10};
    test(e,f);
    #endif
    int g[] = {1,15,16,27,37,0,0,0};
    int h[] = {-1,20,40};
    test(g,h);



    return 0;
}

