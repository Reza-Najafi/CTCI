#include <iostream>
#include <string>
#include <vector>
using namespace std;

int rec(vector<string> in, string str, int l, int h)
{
    // Check the termination condition
    if (l > h)
    {
        return -1;
    }

    // Check the mid point
    int m = (l + h) / 2;
    if (in[m] == "")
    {
        int counter = 1;
        while (counter <= m - l)
        {
            int nl = m - counter;
            int nh = m + counter;
            if (nl >= l && in[nl] != "")
            {
                m = nl;
                break;
            }
            if (nh < h && in[nh] != "")
            {
                m = nh;
                break;
            }
            counter++;
        }
        if (m == (l + h) / 2)
        {
            return -1;
        } // nothing but empty strings can be found in here
    }
    if (in[m] == str)
    {
        return m;
    }
    if (in[m].compare(str) < 0)
    {
        return rec(in, str, m + 1, h);
    }
    return rec(in, str, l, m - 1);
}
int sparse_find(vector<string> in, string &target)
{
    int num = in.size();
    cout << "Length of input " << num << endl;
    return rec(in, target, 0, num);
}

int main()
{
    vector<string> lst = {"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""};
    cout << "Input string: \n";
    for (auto &s : lst)
    {
        cout << s << " , ";
    }
    cout << endl;
    string target;
    cout << "Insert the string you are looking for ?"<< endl;
    
    cin >> target;
    cout << "The taget: " << target << " is at idx " << sparse_find(lst, target);
}
