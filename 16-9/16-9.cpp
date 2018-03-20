#include "Matrix.h"
#include <iostream>
#include <queue>
using namespace std;

template<typename T, typename S>
pair< T,  S>  operator+(pair<T,S> p1, pair<T,S> p2){
    pair<T,S> r;
    r.first = p1.first + p2.first;
    r.second = p1.second + p2.second;
    return r;
}

bool withinRange(pair<int, int> p, pair<int, int> size) {
    return (p.first < size.first && p.second < size.second && p.first >=0 && p.second >=0)  ;
}

int pondSizeBFS(Matrix& m, pair<int, int> p) {
    if(m.at(p) != 0 ) {return 0;}

    static auto neighbours = {make_pair(1,0),make_pair(0,1), make_pair(-1,0), make_pair(0,-1),
        make_pair(1,1),make_pair(-1,-1), make_pair(-1,1), make_pair(1,-1)};

    int count = 0;
    queue<pair<int,int>> q;
    q.push(p);
    m.at(p) = -1;
    while(!q.empty())
    {
        auto thisP = q.front();
        count++;
        for (auto& n:neighbours){
            auto newP = n+thisP;
            if(withinRange(newP,m.size()) && m.at(newP) == 0){
                m.at(newP) = -1;
                q.push(newP);
            }
        }
        q.pop();
    }
    return count;
}

vector<int> pondSizes(Matrix& m) {
    vector<int>  v;
    for(int i = 0; i < m.size().first; i++) {
        for(int j = 0; j < m.size().second;j++){
           int count = pondSizeBFS(m,make_pair(i,j));
           if(count != 0) {
               v.push_back(count);
           }
        }
    }
    return v;
}

int main() {
    const int h = 7;
    const int w = 9;
    Matrix m(h,w);
    m[3][4] = 0;
    m[4][5] = 0;
    m[5][6] = 0;
    m[3][3] = 0;
    m[3][7] = 0;
    m[2][6] = 0;
    m[1][5] = 0;
    m[0][4] = 0;
    m[0][6] = 0;
    m.print();
    auto v = pondSizes(m);
    cout << "num of ponds "<< v.size()<<endl;
    for(auto& i : v){
        cout <<"pond size "<< i << endl;
    }
}
