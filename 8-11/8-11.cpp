#include <iostream>
#include<set>

using namespace std;


std::set<int> _set;

int recurs(int n, int s){
  if(n<0) {
    return 0;
  }

  if(n==0) {
    // here is where we check if the set is unique or not
    if(_set.find(s) == _set.end()){
      _set.insert(s);
      return 1;
    }
    return 0;
  }

  return (recurs(n-1 , s+1)+recurs(n-5, s+10)+recurs(n-10, s+100)+recurs(n-25, s+1000));
}

int main(){

    int n;
    cin >> n;
#if 0
    for(int i=0 ; i < n; i++){
        _set.clear();
        int out = recurs(i, 0);
        cout << "input: "<<i << " output: "<< out<<endl;
    }
#else
        _set.clear();
        int out = recurs(n, 0);
        cout << "input: "<<n << " output: "<< out<<endl;
#endif
    
    cin >> n;
}