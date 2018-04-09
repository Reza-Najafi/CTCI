#include <iostream>
#include <array>
#include "Matrix.h"
using namespace std;
typedef array<int,2> Idx;
typedef array<Idx,2> Rect;
Idx non = {-1,-1};
Rect res = {non,non};
int max = 0;

int getSum(Matrix& m, int r1, int r2, int col) {
    int res = m[r2][col];
    res -= ((r1-1)>=0) ? m[r1-1][col] : 0;
    return res;
}

Matrix sumUpColumns(Matrix& m) {
    int w = m.size().first;
    Matrix ret = m;
    for(int col = 0; col < w; col++) {
        for(int r = 0; r < w; r++) {
            ret[r][col] += ((r-1 >= 0) ? ret[r-1][col]:0);
        }
    }
    //cout << "column accumulated :\n";
    //ret.print();
    return ret;
}
pair<Rect,int> find(Matrix& m) {
    int w = m.size().first;
    int max = 0;
    Rect ret;
    for(int r1 = 0; r1<w; r1++) {
        for(int r2 = r1; r2 < w; r2++) {
            int sum = 0;
            int start = 0;
            for(int col = 0; col < w; col++) {
                sum += getSum(m,r1,r2,col);
                if(sum < 0) {
                    sum = 0;
                    start = col+1;
                } else {
                    if(sum > max) {
                        ret[0] = {r1,start};
                        ret[1] = {r2,col};
                        max = sum;
                    }
                }
            }
        }
    }
    return make_pair(ret,max);
}

pair<Rect,int>  findMaxSubMat(Matrix& m) {
    Matrix r =  sumUpColumns(m);
    return find(r);
}

int main() {
    int w = 4;
    Matrix m(w,w);
    m[0][0] = -10; m[0][1] = -3;  m[0][2] = 5; m[0][3] = -7;
    m[1][0] = -1;  m[1][1] = 2; m[1][2] = 2; m[1][3] = -2;
    m[2][0] = 4;  m[2][1] = 1;  m[2][2] = -1; m[2][3] = 8;
    m[3][0] = -2; m[3][1] = 5;  m[3][2] = 8; m[3][3] = -7;
    m.print();
    auto ret = findMaxSubMat(m);
    cout << "max is "<< ret.second << " start : (" << ret.first[0][0] <<" , " << ret.first[0][1] << " )" <<
    " end : (" << ret.first[1][0] <<" , " << ret.first[1][1] << " )";
}
