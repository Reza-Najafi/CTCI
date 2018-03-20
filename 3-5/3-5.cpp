
#include <iostream>
#include <stack>
//#include <vector>
using namespace std;
void sortStack(stack<int>& s){
    stack<int> s1;
    int sz = s.size();
    while(sz-->=0){
        int min = s.top();
        while(!s.empty()) {
            if(s.top()< min) {
                min = s.top();
            }
            s1.push(s.top());
            s.pop();
        }
        while(!s1.empty()) {
            if(s1.top() != min){
                s.push(s1.top());
            }
            s1.pop();
        }
        s.push(min);
    }
}

int main()
{
    int arr[] = {1,5,0,-2,4,2,3,0,1,7,9,-5};
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
