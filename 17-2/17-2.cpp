#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>
using namespace std;
int getRand(int off, int len) {
    return (off+(rand()%len));
}
void shuffleRec(vector<int>& v, int s) {
    if(s <= 1) return;
    shuffleRec(v,s-1);
    int idx = getRand(0,s);
    swap(v[idx],v[s-1]);
}
void shuffle(vector<int>& v) {
    shuffleRec(v, v.size());
}
int main() {
    vector<int> v = {0,1,2,3,4,5};
    srand(time(0));
    for(int i = 0; i < 30; i++) {
        shuffle(v);
        for(auto& e: v) cout << e << " ";
        cout << endl;
    }
}
