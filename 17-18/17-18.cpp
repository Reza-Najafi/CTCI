/******************************************************************************************************
* Seyedreza Najafi , March-2018
* Solution to the following problem from the "Cracking the Coding Interview" book, 6th edition
*
* 17.18 Shortest Supersequence
*
******************************************************************************************************/
#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;


pair<int,int> shortestSubSequence(vector<int>& a, vector<int>& b) {
    map<int, int> bmap;
    vector<priority_queue<int>> vq(a.size());
    for(auto& e: b)
        bmap.insert(make_pair(e,0));

    for(int i = 0; i < a.size(); i++) {
        if(bmap.find(a[i]) != bmap.end()) {
            for(int j = bmap[a[i]] ; j <= i; j++) {
                vq[j].push(i);
            }
            bmap[a[i]] = i+1;
        }
    }
    for(auto & e: bmap) {
        for(int j = e.second ; j <  a.size(); j++) {
            vq[j].push(2*a.size());
        }
    }

    pair<int,int> ret = make_pair(-1,a.size());
    for(int i = 0; i < a.size(); i++) {
        int l = vq[i].top() -i;
        if(l <a.size() && l < ret.second) {
            ret.second = l;
            ret.first = i;
        }
    }
    return ret;
}

int main() {
    vector<int> a = {7,5,9,0,2,1,3,5,7,9,1,1,5,8,8,9,7};
    vector<int> b = {1,5,9};
    auto r = shortestSubSequence(a,b);
    cout << "start: " << r.first << " len: "<< r.second << endl;
}
