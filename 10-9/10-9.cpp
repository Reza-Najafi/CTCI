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

pair<int , int> find_rec(Matrix& m, pair<int, int> p1, pair<int, int>p2, int t){
  if(p1.first > p2.first || p1.second > p2.second) {return make_pair(-1,-1);}
  if(t < m[p1.first][p1.second] || t > m[p2.first][p2.second] ) {return make_pair(-1,-1);}
  auto mid = make_pair((p1.first+p2.first)/2,(p1.second+p2.second)/2);
  if(t == m[mid.first][mid.second]) {return mid;}
  if(t < m[mid.first][mid.second])  { return find_rec(m, p1,mid,t); }
  auto f1 = find_rec(m,mid,p2,t);
  if(f1.first != -1) {return f1;}
  auto f2 = find_rec(m, make_pair(p1.first, mid.second), make_pair(mid.first,p2.second), t);
  if(f2.first != -1) {return f2;}
  auto f3 = find_rec(m, make_pair(p1.second, mid.first), make_pair(mid.second,p2.first), t);
  if(f3.first != -1) {return f3;}
}
pair<int , int> find2D(Matrix& m, int t){
  auto sz = m.size();
  return(find_rec(m, make_pair(0,0), make_pair(sz.first-1, sz.second-1), t));
}
int main() {
  Matrix m(8,9);
  auto f = find2D(m, 48);
  cout << f.first << " , "<< f.second << " "<<endl;
}
