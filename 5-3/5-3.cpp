#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

int findmax(vector<int>& v) {
    int max = 0;
    int sz = v.size()-1;
    for(int i = 0; i < sz; i++) {
        int new_max = v[i]+v[i+1]+1;
        if(new_max > max)
            max = new_max;
    }
    if(v.size() == 1)
        return v[0]+1;
    return max;
}

int longest1seq(int x) {
    int max = 0;
    int zcount = 0;
    int ocount = 0;
    vector<int> v;
    for(int i = 0; i < 32; i++) {
        int b = ((x & (1 << i)) != 0) ? 1 :0;
        if(b==0) {
            zcount++;
            if(zcount >=2) {
                int m = findmax(v);
                if(m>max)
                    max = m;
                zcount = 0;
                v.clear();
            } else {
                v.push_back(ocount);
            }
            ocount = 0;
        } else {
            ocount++;
            zcount = 0;
        }
    }
    int last_max = findmax(v);
    return ((max>last_max) ? max : last_max);
}

int main() {
    int xarr[] ={ 0b11011101111 , 0b11011001111 , 0b110011101111 , 0b00010001001, 0b000111110010010001, 0b0};
    for(auto& x : xarr)
        cout << bitset<16>(x)<< " : " <<longest1seq(x) << endl;
}
