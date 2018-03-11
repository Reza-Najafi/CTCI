// 87.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <vector>
#include <string>
using namespace std;
void perm(string &in, vector<string> &out)
{
    if (0 >= in.length())
    {
        return;
    }
    string c = in.substr(0, 1);
    in.erase(0,1);

    int currSize = out.size();
        
    for (int i = 0; i < currSize; i++)
    {

        for (int j = 0; j < out[i].length(); j++)
        {
            string newS = out[i];
            newS.insert(j, c);
            out.push_back(newS);
        }
        out[i] += c;
    }
    if (currSize == 0)
    {
        out.push_back(c);
    }

    perm(in, out);
    
}
int main()
{
    string in;
    cin >> in;
    vector<string> l;
    perm(in, l);
    for (string &s : l)
    {
        cout << s << endl;
    }
    cin >> in;
}
