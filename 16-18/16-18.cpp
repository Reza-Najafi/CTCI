#include <iostream>
#include <string>
#include <vector>
using namespace std;
int match(string& pat, string& s) {
    int na = 0, nb = 0;
    for(auto &c : pat){
        if(c == 'a'){
            na++;
        }
        else if (c == 'b'){
            nb++;
        } else {
            return -1;
        }
    }
    int la =0, lb =1;
    vector<pair<int,int>> sol;
    while(++la <= ((s.length()-nb*1)/na)) {
        if((s.length()-na*la)%nb==0) {
            lb = (s.length()-na*la)/nb;
            auto p = make_pair(la,lb);
            sol.push_back(p);
        }
    } 
    for(auto& p: sol){
        cout << p.first << " , "<< p.second << endl;
    }
}

int main(){
    string pat, str;
    cout << "Insert Pattern" << endl;
    cin >> pat;
    cout << "Insert String" << endl;
    cin >> str;
    cout << "string length "<< str.length()<< endl;
    match(pat, str);
}