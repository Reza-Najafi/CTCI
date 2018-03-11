#include <iostream>
#include<set>
#include<vector>
#include<string>
using namespace std;



void create(int n, vector<string>& l){
  int sz = l.size();
  for(int i=sz-1; i>=0; i--){
    string s = l[i];
    l.push_back(s+"()");
    if((s+"()") != ("()"+s)) {
      l.push_back("()"+s);
    }
    l.push_back("("+s+")");
    l.erase(l.begin()+i);
  }
  if(sz==0){
    l.push_back("()");
  }
  if(l[0].length() <= (n-2)){
    // has room for more
    create(n,l);
  }
}

int main() {
    vector<string> l;
    int len;
    cin>>len;
    create(len,l);
    cout << "size " <<l.size() << endl;
    for(string& s: l){
        cout << s<<endl;
    }
    cin>>len;
}