#include <iostream>
#include <iomanip>
class Matrix{
public:
    Matrix(Matrix& other) {
        auto sz = other.size();
        ROW = sz.first;
        COL = sz.second;
        m = new int[ROW*COL];
        for(int i = 0; i < ROW; i++) {
            for(int j = 0; j < COL; j++) {
                m[i*COL+j] = other[i][j];
            }
        }
    }
    Matrix(Matrix&& other) {
        m = other.m;
        auto sz = other.size();
        ROW = sz.first;
        COL = sz.second;
        other.m = NULL;
    }
    Matrix(int h, int w):ROW(h),COL(w) {
        m = new int[ROW*COL];
        zero();
    }
    void operator=(Matrix& other) {
        if(other.size() != this->size())
        for(int i = 0; i < ROW; i++) {
            for(int j = 0; j < COL; j++) {
                m[i*COL+j] = other[i][j];
            }
        }
    }
    void zero() {
        for(int i = 0; i < ROW; i++) {
            for(int j = 0; j < COL; j++) {
                m[i*COL+j] = 0;
            }
        }
    }
    void fill() {
        int count = 0;
        for(int i = 0; i < ROW; i++) {
            for(int j = 0; j < COL; j++) {
                m[i*COL+j] = count++;
            }
        }
    }
    void print() {
        std::cout << "["<< std::endl;
        for(int i = 0; i < ROW; i++){
            std::cout << "[ ";
            for(int j = 0; j < COL; j++){
                std::cout << std::setw(4) << (*this)[i][j] << ((j==(COL-1)) ? "":" , ");
            }
            std::cout << " ]" << std::endl;
        }
        std::cout << "]"<< std::endl;
    }

    ~Matrix(){ if(m != NULL) {delete[] m; m = NULL;} }
    int* operator[](int i){ return (&m[i*COL]); }
    std::pair<int, int> size() { return std::make_pair(ROW,COL);}
    int& at(std::pair<int, int> p) { return (*this)[p.first][p.second];}
private:
    int* m;
    int ROW;
    int COL;
};
