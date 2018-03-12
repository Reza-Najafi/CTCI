#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<pair<string , string>> match(string& pat, string& s) {
    vector<pair<string , string>> v;
    int na = 0, nb = 0;
    for(auto &c : pat){
        if(c == 'a'){
            na++;
        }
        else if (c == 'b'){
            nb++;
        } else {
            return v;
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
        cout << "a and b lengths: "<< p.first << " , "<< p.second << endl;
        string a_code= "", b_code="";
        int off;
        bool matched = true;
        off = 0;
        for(auto& c: pat){   
            if(c=='a'){
                if(a_code==""){
                    a_code = s.substr(off,p.first);
                } else {
                    if(a_code != s.substr(off,p.first)){
                        matched = false;
                        break;
                    }
                }
                off += p.first;
            }
            if(c=='b'){
                if(b_code==""){
                    b_code = s.substr(off,p.second);
                } else {
                    if(b_code != s.substr(off,p.second)){
                        matched = false;
                        break;
                    }
                }
                off += p.second;
            }            
        }
        if(matched){
            v.push_back(make_pair(a_code, b_code));
        }
    }
    return v;
}

int main(){
    string pat, str;
    cout << "Insert Pattern" << endl;
    cin >> pat;
    cout << "Insert String" << endl;
    cin >> str;
    cout << "string length "<< str.length()<< endl;
    auto v = match(pat, str);
    if(!v.empty()){
        for(auto& p: v){
            cout << "<a_code> "<< p.first << " <b_code> " <<p.second  << endl;
        }
        return 0;
    }
    cout << "No match was found!";
    return -1;

}