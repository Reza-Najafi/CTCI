
#include <iostream>
#include <string>

using namespace std;
bool one_change(string& s1, string& s2)
{
  int l1 = s1.length();
  int l2 = s2.length();
  int oneFound = 0;
  if(l1 == l2) {
    for(int i=0; i < l1; i++) {
      if(s1[i] != s2[i]) {
        if(oneFound==0){
          oneFound++;
          continue;
        } else {
          return false;
        }
      }
    }
  } else {
    string& long_str = (l1>l2) ? s1 : s2;
    string& short_str = (l1>l2) ? s2 : s1;
    int i = 0, j = 0;
    int& longLen = (l1>l2) ? l1 : l2;
    int& shortLen = (l1>l2) ? l2 : l1;
    while (i<longLen && j<shortLen){
      if(long_str[i] != short_str[j]){
        if(oneFound==0) {
          oneFound++;
          i++;
        } else {
          return false;
        }
      }
      i++;j++;
    }
  }
  return true;
}



int main()
{
    string s1,s2;
    cin >> s1;
    cin >> s2;
    string outs = (one_change(s1,s2)?"Yes":"No");
    cout <<">"<< outs <<"<" <<endl;
    return 0;
}
