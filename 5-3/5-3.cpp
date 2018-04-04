#include <iostream>
#include <bitset>
using namespace std;


class FindMax {
public:
    FindMax() {clear();}
    void clear() {c= 0; p = 0; max = 0;}
    void push(int x) { p = c; c= x; if(p+c+1 > max) max = p+c+1;}
    int getMax() {return max;}
private:
    int c;
    int p;
    int max;
};



int longest1seq(int x) {
    int max = 0;
    int zcount = 0;
    int ocount = 0;
    FindMax fm;
    for(int i = 0; i < 32; i++) {
        int b = ((x & (1 << i)) != 0) ? 1 :0;
        if(b==0) {
            zcount++;
            if(zcount ==2) {
                int m = fm.getMax();
                if(m>max)
                    max = m;
                zcount = 0;
                fm.clear();
            } else {
                fm.push(ocount);
            }
            ocount = 0;
        } else {
            ocount++;
            zcount = 0;
        }
    }
    int last_max = fm.getMax();
    return ((max>last_max) ? max : last_max);
}

int main() {
    int xarr[] ={ 0b11011101111 , 0b11011001111 , 0b110011101111 , 0b00010001001, 0b000111110010010001, 0b0};
    for(auto& x : xarr)
        cout << bitset<16>(x)<< " : " <<longest1seq(x) << endl;
}
