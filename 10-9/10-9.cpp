#include <stdio.h>

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
  auto mid = make_pair((p1.first+p2.first)/2,(p1.second+p2.second)/2);
  if(t == m[mid.first][mid.second]) {return mid;}
  if(mid.first == p1.first && mid.second == p1.second ) {
    if(t == m[mid.first+1][mid.second]) {return(make_pair(mid.first+1,mid.second));}
    if(t == m[mid.first][mid.second+1]) {return(make_pair(mid.first,mid.second+1));}
    if(t == m[mid.first+1][mid.second+1]) {return(make_pair(mid.first+1,mid.second+1));}
    return make_pair(-1,-1);
  }

  if(t < m[p1.first][p1.second] || t > m[p2.first][p2.second] ) {return make_pair(-1,-1);}

  if(t > m[mid.first][mid.second])
  {
    auto f4 = find_rec(m,mid,p2,t);
    if(f4.first != -1) {return f4;}
  } else
  {
    auto f1 = find_rec(m, p1,mid,t);
    if(f1.first != -1) {return f1;}
  }
  auto f2 = find_rec(m, make_pair(p1.first, mid.second+1), make_pair(mid.first-1,p2.second), t);
  if(f2.first != -1) {return f2;}

  auto f3 = find_rec(m, make_pair(mid.first+1, p1.second), make_pair(p2.first, mid.second-1), t);
  if(f3.first != -1) {return f3;}

  return (make_pair(-1,-1));
}
pair<int , int> find2D(Matrix& m, int t){
  auto sz = m.size();
  return(find_rec(m, make_pair(0,0), make_pair(sz.first-1, sz.second-1), t));
}
int main() {
  Matrix m(7,9);
  m.print();
  auto f = find2D(m, 61);
  cout << f.first << " , "<< f.second << " "<<endl;
}
