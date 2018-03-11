#include <iostream>
#include <iomanip>
#include <algorithm>    // std::swap


using namespace std;
class SQMatrix{
public:
    SQMatrix(int n):N(n) { 
        m = new int[N*N];
        int count = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                m[i*N+j] = count++;
            }
        }
    }
    void print() {
        cout << "["<< endl;
        for(int i = 0; i < N; i++){
            cout << "[ ";
            for(int j = 0; j < N; j++){
                cout << setw(4) << (*this)[i][j] << ((j==N-1)?"":" , ");
            }
            cout << " ]" << endl;
        }
        cout << "]"<< endl;
    }
    void diagFlip() {
        // flip diagonally
        for(int i = 0; i < N-1; i++){
            for(int j=i+1; j < N; j++){
                swap((*this)[i][j], (*this)[j][i]);
            }
        }
    }
    void horizFlip() {
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N/2; j++){
                swap((*this)[i][j], (*this)[i][-j+N-1]);
            }
        }
    }
    ~SQMatrix(){ delete[] m; }
    int* operator[](int& i){ return (&m[i*N]); }
private:
    int* m;
    int N;
};
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
    void transpose(){
        // flip diagonally
        int row = ROW;
        int col = COL;

    }
    ~Matrix(){ delete[] m; }
    int* operator[](int& i){ return (&m[i*COL]); }
private:
    int* m;
    int ROW;
    int COL;
};

int main() {
    SQMatrix m(4);
    m.print();
    m.diagFlip();
    cout << "after flipping diagonally\n";
    m.print();
    m.horizFlip();
    cout << "after flipping horizontally\n";
    m.print();
    return 0;
}