#include <iostream>
#include <vector>


#include <cstdlib>
#include <time.h>

using namespace std;
int getRand(int off, int len) {
    return (off+(rand()%len));
}

void subsetRec(vector<int>& s, vector<int>& ret, int len){
    if(len <= ret.size()) return;
    subsetRec(s,ret,len-1);
    int id = getRand(0,s.size());
    if(id < ret.size()) ret[id] = s[len-1];
}

vector<int> subset(vector<int>& s, int m) {
    vector<int> v;
    if(m > s.size()) return v;
    vector<int> ret(m);
    for(int i = 0; i < m; i++) ret[i] = s[i];
    subsetRec(s,ret,s.size());
    return ret;
}



int main() {
    vector<int> v = {0,1,2,3,4,5};
    srand(time(0));
    for(int i = 0; i < 20; i++) {
        auto s = subset(v,2);
        for(auto& e: s) cout << e << " ";
        cout << endl;
    }
}
