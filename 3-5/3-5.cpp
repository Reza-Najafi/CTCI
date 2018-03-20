
#include <iostream>
#include <stack>
//#include <vector>
using namespace std;
void sortStack(stack<int>& s){
    stack<int> s1;
    int sz = s.size();
    int i = 0;
    while(i++ < sz){
        int min = s.top();
        while(s.size()> (i-1)) {
            if(s.top()< min) {
                min = s.top();
            }
            s1.push(s.top());
            s.pop();
        }
        s.push(min);
        bool foundMin = false;
        while(!s1.empty()) {
            if(s1.top() != min || foundMin){
                s.push(s1.top());
            }
            if(s1.top() == min){
                foundMin = true;
            }
            s1.pop();
        }
    }
    while(!s.empty()){
        s1.push(s.top());
        s.pop();
    }
    s = s1;
}

int main()
{
    int arr[] = {1,5,0,-2,4,2,3,0,1,7,9,-5};
    cout << sizeof(arr)/sizeof(arr[0]) << endl;
    stack<int> s;
    for(auto& i : arr){
        s.push(i);
    }
    sortStack(s);
    while(!s.empty()) {
        cout << s.top() << " , ";
        s.pop();
    }
    return 0;
}
