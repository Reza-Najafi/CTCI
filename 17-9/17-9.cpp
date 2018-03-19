#include <iostream>
#include <tuple>
#include <map>
using namespace std;

class KthMultiple {
public:
    auto generate(int k){
        numList.clear();
        auto p  = make_pair(1,make_tuple(0,0,0));
        numList.insert(p);
        int iter = 0;
        auto val = p;
        while(iter++ <= k){
            val = generateRec();
        }
        return val;
    }
private:
    pair<long long  int, tuple< int, int, int>> generateRec(){
        auto it = numList.begin();
        auto val = it->first;
        auto fact = it->second;
        auto thirdFactor = get<0>(fact);
        auto fifthFactor = get<1>(fact);
        auto seventhFactor = get<2>(fact);
        auto newNum1 = make_pair(val*3, make_tuple(thirdFactor+1, fifthFactor, seventhFactor));
        if(numList.find(val*3) == numList.end()){
            numList.insert(newNum1);
        }
        auto newNum2 = make_pair(val*5, make_tuple(thirdFactor, fifthFactor+1, seventhFactor));
        if(numList.find(val*5) == numList.end()){
            numList.insert(newNum2);
        }
        auto newNum3 = make_pair(val*7, make_tuple(thirdFactor, fifthFactor, seventhFactor+1));
        if(numList.find(val*7) == numList.end()){
            numList.insert(newNum3);
        }        
        
        auto newit = numList.begin();
        auto retVal = *newit;
        numList.erase(newit);
        return retVal;
    }
    map<long long  int, tuple< int, int, int>> numList;
};






class KthMultipleStupid{
public:
    void generate(int k){
        auto p  = make_pair(1,make_tuple(0,0,0));
        generate(p,k);
    }
    void generate(pair<long long int, tuple<int, int, int>> p, int k){
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
    auto getval(int k) 
    {
        auto begIt = numList.begin();
        advance(begIt, k);
        return begIt;
    }
    auto listEnd()
    {
        return numList.end();
        
    }
private:
    map<long long  int, tuple< int, int, int>> numList;
};

int main()
{
    KthMultiple kth;
    int val = 20;

    for(int i = 0; i <val; i++ ){
        auto it = kth.generate(i);
        cout << i<<"th factor is "<<  it.first << " factors are : " << get<0>(it.second) << " , " << get<1>(it.second) << " , " << get<2>(it.second) << endl;
    }

    return 0;
}

