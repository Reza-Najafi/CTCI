
#include <set>
#include <string>
#include <iostream>

using namespace std;


bool segment(set<string>& s, string&& str)
{
  if(str.length() == 0){
    // we've got to the end 
    return true;
  }
  int len = 1;
  while (len <= str.length())
  {
    if(s.find(str.substr(0,len))!=s.end()) 
    {
      if(segment(s,str.substr(len)))
      {
        cout << str.substr(0,len) << " , ";
        return true;
      }
    }
    len++;
  }
  return false;
}

int main(){
    set<string> s= { "ab", "aba"};
    string str;

    cin >> str;
    cout << (segment(s,string(str)) ? "Yes":"No");
}