#include <iostream>
using namespace std;

//recursive version
int addrec(int a , int b) {
    if(a==0) return b;
    if(b==0) return a;
    return addrec(a^b, (a&b)<<1);
}

int add (int a , int b) {
    if(a==0) return b;
    if(b==0) return a;
    while (b!=0) {
        int ta = a;
        a = a^b;
        b = (ta&b) << 1;
    }
    return a;
}


int main() {
    int a = 56;
    int b = 35;
    cout << add(a,b) << endl;
}
