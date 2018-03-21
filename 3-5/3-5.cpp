
#include <iostream>
#include <stack>
//#include <vector>
using namespace std;
void sortStack(stack<int>& s){
    stack<int> s1;
    int sz = s.size();
    int sortedCount = 0;
    while(sortedCount < sz){
        int max = s.top();
        bool start = true;
        while(s.size()> sortedCount) {
            if(s.top()> max) {
                s1.push(max);// put the previously considered max on the aux stack
                max = s.top();// set the new max
            } else {
                // we don't want to put the initialized max value at the start and create duplicates
                if(!start){ s1.push(s.top()); }
                start = false;
            }
            s.pop();
        }
        s.push(max);
        sortedCount++;
        while(!s1.empty()) {
            s.push(s1.top());
            s1.pop();
        }
    }

}

int main()
{
    int arr[] = {1,5,0,-2,4,2,3,0,1,7,9,-5};

    stack<int> s;
    for(auto& i : arr){
        s.push(i);
    }
    cout << s.size()<< endl;
    sortStack(s);
    cout << s.size()<< endl;
    while(!s.empty()) {
        cout << s.top() << " , ";
        s.pop();
    }
    return 0;
}
