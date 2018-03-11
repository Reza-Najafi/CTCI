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
private:
    int* m;
    int ROW;
    int COL;
};

void zeroMatrix(Matrix& m) {
    auto sz = m.size();

    int* row = new int[sz.first];
    int* col = new int[sz.second];

    for(int i = 0; i <sz.first; i++){row[i] = -1;}
    for(int j = 0; j <sz.second; j++){col[j] = -1;}

    for (int i = 0; i < sz.first; i++) {
        for (int j = 0; j < sz.second; j++) {
            if(m[i][j] == 0){
                row[i] = 0;
                col[j] = 0;
            }
        }
    }

    for(int i = 0; i <sz.first; i++){
        if(row[i] == 0){
            for(int j = 0; j < sz.second; j++){
                m[i][j] = 0;
            }
        }
    }

    for(int i = 0; i <sz.second; i++){
        if(col[i] == 0){
            for(int j = 0; j < sz.first; j++){
                m[j][i] = 0;
            }
        }
    }

    delete [] row;
    delete [] col;
}

int main() {
    Matrix m(4,5);
    m.print();
    cout << m.size().first<< " "<< m.size().second << endl;
    m[2][3] = 0;
    zeroMatrix(m);
    m.print();
    return 0;
}
