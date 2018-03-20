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
    vector<pair<string, map<char, int>>> v;
    void createHist(string & in) {
        for(auto& c : in){
            if(m.find(c) == m.end()) {
                m.insert(make_pair(c,1));
            } else {
                m[c] += 1;
            }
        }
    }

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
};

int main() {
    string s;
    cin >> s;
    Perm p;
    auto v = p.getPerm(s);
    for(auto e: v){
        cout << e.first<< endl;
    }
}
