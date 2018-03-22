#include <iostream>
#include <iomanip>

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

    ~Matrix(){ delete[] m; }
    int* operator[](int i){ return (&m[i*COL]); }
    std::pair<int, int> size() { return std::make_pair(ROW,COL);}
    int& at(std::pair<int, int> p) { return (*this)[p.first][p.second];}
private:
    int* m;
    int ROW;
    int COL;
};
