/******************************************************************************************************
* Seyedreza Najafi , March-2018
* Solution to the following problem from the "Cracking the Coding Interview" book, 6th edition
* 
* 17.16 The Masseuse
*
******************************************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class FindLongestComb{
    vector <int > res;
public:
    int find(vector <int>&in) {
        count(in,false,0,0);
        int cmax = 0;
        for(auto& e: res){
            if(e>cmax){cmax = e;};
        }
        return cmax;
    }
    void count(vector < int >&in, bool prevAct, int idx, int currCount)
    {
    
    	if (idx >= in.size())
    	{
    		res.push_back(currCount);
    		return;
    	}
    
    	if (prevAct)
    	{
    		// previous appointment taken have no option but not taking this one
    		count(in, false, idx + 1, currCount);
    	}
    	else {
    		// previous appointment not taken can accept/not accept this one
    		count(in, true, idx + 1, currCount + in[idx]);
    		count(in, false, idx + 1, currCount);
    	}
    }
};

int main() {
    FindLongestComb flb;
    vector<int> v = {30,15,60,75,45,15,15,45};
    cout << "The longest working hours " << flb.find(v)<<endl;
}