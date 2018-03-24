#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
class Perm {
public:
    auto& getPerm(string& in ){
        slen = in.length();
        createHist(in);
        findPerm();
        return v;
    }

private:
    map<char, int> m;
    int slen;

    void createHist(string & in) {
        for(auto& c : in){
            if(m.find(c) == m.end()) {
                m.insert(make_pair(c,1));
            } else {
                m[c] += 1;
            }
        }
    }
#if 1
    vector<string> v;
    void findPermRec(string currStr) {
        if(currStr.length() == slen) {v.push_back(currStr);return;}
        for(auto& p: m) {
            char c = p.first;
            int count = p.second;
            if(count > 0) {
                m[c] -=1;
                string newS = currStr;
                newS.push_back(c);
                findPermRec(newS);
                m[c] +=1;
            }
        }
    }
    void findPerm() {
        findPermRec("");
    }
#else
    vector<pair<string, map<char, int>>> v;
    void findPerm()
    {
        int vSize = v.size();

        for( int i = 0; i < vSize; i++)
        {
            for(auto& c: m)
            {
                auto newS = v[i].first;
                auto newM = v[i].second;

                int used = 0;
                auto it = newM.find(c.first);
                if( it != newM.end()) {
                    used = it->second;
                }
                if(c.second > used)
                {
                    if(used == 0){
                        newM.insert(make_pair(c.first,1));
                    } else {
                        newM[c.first] +=1;
                    }

                    newS += string(1,c.first);
                    v.push_back(make_pair(newS,newM));
                }
            }
        }
        v.erase(v.begin(),v.begin()+vSize);

        if(vSize == 0)
        {
            for(auto& c: m)
            {
                map<char, int> newM;
                newM.insert(make_pair(c.first,1));
                v.push_back(make_pair(string(1,c.first),newM));
            }
        }

        if(v[0].first.size()<slen) {
            findPerm();
        }

    }
    #endif
};

int main() {
    string s;
    cin >> s;
    Perm p;
    auto v = p.getPerm(s);
    for(auto e: v){
        cout << e<< endl;
    }
}
