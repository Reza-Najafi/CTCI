
#include <iostream>
#include <queue> //pq
#include <functional> // greator
using namespace std;
class Median{
public:
    float insert(int m)
    {
        // m < maxH -> goes in maxH, reballance the heap sizes
        if(maxH.empty() || m < maxH.top()){
            maxH.push(m);
        }
        // m > minH -> goes in minH, reballance the heap sizes
        else if(minH.empty() || m >= minH.top()){
            minH.push(m);
        }
        // not above cases put it in the heap with less elements
        else {
            if(minH.size() < maxH.size()){
                minH.push(m);
            } else {
                maxH.push(m);
            }
        }
        reballance();
        if(minH.size() == maxH.size()) {
            return ((float)minH.top()+(float)maxH.top())/2;
        } else if(minH.size() < maxH.size()){
            return maxH.top();
        } else {
            return minH.top();
        }
    }
    void print(){
        priority_queue<int> _maxH = maxH;
        priority_queue<int,vector<int>,greater<int>> _minH = minH;
        while(!_maxH.empty()){
            cout << _maxH.top()<<" , ";_maxH.pop();
        }
        cout << " _ ";
        while(!_minH.empty()){
            cout << _minH.top()<<" , ";_minH.pop();
        }
        cout << endl;
    }
private:
    void reballance() {
        if(abs((int)(maxH.size() -minH.size()))<=1 ){return;}
        if(maxH.size() > minH.size()){
            minH.push(maxH.top());
            maxH.pop();
        } else {
            maxH.push(minH.top());
            minH.pop();
        }
    }

    priority_queue<int> maxH;
    priority_queue<int,vector<int>,greater<int>> minH;
};


int main()
{
    Median md;
    int input_list[] = {1,10,4,5,69,25,21,63,17,16,15,1,7,12,15,16};

    for(int i = 0; i < sizeof(input_list)/sizeof(input_list[0]); i++) {

        cout << "[ "<< i <<" ] median is " << md.insert(input_list[i])<< endl;
        md.print();
    }

    return 0;
}
