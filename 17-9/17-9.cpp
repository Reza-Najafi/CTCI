#include <iostream>
#include <tuple>
#include <map>
using namespace std;
class KthMultiple{
public:
    void generate(int k){
        auto p  = make_pair(1,make_tuple(0,0,0));
        generate(p,k);
    }
    void generate(pair<int, tuple<int, int, int>> p, int k){
        auto val = p.first;
        auto fact = p.second;
        auto thirdFactor = get<0>(fact);
        auto fifthFactor = get<1>(fact);
        auto seventhFactor = get<2>(fact);
        if(thirdFactor < k ) {
            auto newNum = make_pair(val*3, make_tuple(thirdFactor+1, fifthFactor, seventhFactor));
            if(numList.find(val*3) == numList.end()){
                numList.insert(newNum);
            }
            generate(newNum,k);
        }
        if(fifthFactor < k ) {
            auto newNum = make_pair(val*5, make_tuple(thirdFactor, fifthFactor+1, seventhFactor));
            if(numList.find(val*5) == numList.end()){
                numList.insert(newNum);
            }
            generate(newNum,k);
        }
        if(seventhFactor < k) {
            auto newNum = make_pair(val*7, make_tuple(thirdFactor, fifthFactor, seventhFactor+1));
            if(numList.find(val*7) == numList.end()){
                numList.insert(newNum);
            }
            generate(newNum,k);
        }
    }
    pair<int, tuple<int, int, int>> getval(int k) {
        auto begIt = numList.begin();
        advance(begIt, k);
        return *begIt;
    }
private:
    map<int, tuple< int, int, int>> numList;
};

int main()
{
    KthMultiple kth;
    int val = 4;
    kth.generate(val);
    for(int i = 0; i <val; i++ ){
        auto it = kth.getval(i);
        cout << i<<"th factor is "<<  it.first << " factors are : " << get<0>(it.second) << " , " << get<1>(it.second) << " , " << get<2>(it.second) << endl;
    }

    return 0;
}
