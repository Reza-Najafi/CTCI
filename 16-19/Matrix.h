#include <iostream>
#include <iomanip>
using namespace std;

class Matrix{
public:
    Matrix(int h, int w):ROW(h),COL(w) {
        m = new int[ROW*COL];
        int count = 0;
        for(int i = 0; i < ROW; i++) {
            for(int j = 0; j < COL; j++) {
                m[i*COL+j] = count++;
            }
        }
    }
    void print() {
        cout << "["<< endl;
        for(int i = 0; i < ROW; i++){
            cout << "[ ";
            for(int j = 0; j < COL; j++){
                cout << setw(4) << (*this)[i][j] << ((j==(COL-1)) ? "":" , ");
            }
            cout << " ]" << endl;
        }
        cout << "]"<< endl;
    }

    ~Matrix(){ delete[] m; }
    int* operator[](int i){ return (&m[i*COL]); }
    pair<int, int> size() { return make_pair(ROW,COL);}
    int& at(pair<int, int> p) { return (*this)[p.first][p.second];}
private:
    int* m;
    int ROW;
    int COL;
};