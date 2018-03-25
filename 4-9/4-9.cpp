#include <vector>
#include <string>
#include "../utilities/Tree.h"
using namespace std;

#include <vector>
#include <string>
#include "Tree.h"
using namespace std;

void weave(vector<int> &sl, int lptr, vector<int> &sr, int rptr, vector<int> &prefix, vector<vector<int>> &ret)
{
    int lsz = sl.size();
    int rsz = sr.size();
    if (lptr == sl.size() && rptr == sr.size())
    {
        ret.push_back(prefix);
        return;
    }
    if (lptr < sl.size())
    {
        prefix.push_back(sl[lptr]);
        weave(sl, lptr + 1, sr, rptr, prefix, ret);
        prefix.pop_back();
    }

    if (rptr < sr.size())
    {
        prefix.push_back(sr[rptr]);
        weave(sl, lptr, sr, rptr + 1, prefix, ret);
        prefix.pop_back();
    }
}

vector<vector<int>> getAllSeq(Node *n)
{
    vector<vector<int>> ret;
    if (!n)
    {
        return ret;
    }
    auto sl = getAllSeq(n->a[0]);
    auto sr = getAllSeq(n->a[1]);
    for (auto &lseq : sl)
    {
        for (auto &rseq : sr)
        {
            vector<int> v = {n->v};
            weave(lseq, 0, rseq, 0, v, ret);
        }
    }

    if (ret.empty())
    {
        vector<int> newV;
        newV.push_back(n->v);
        ret.push_back(newV);
    }
    return ret;
}

int main()
{
    Node *n1 = ct(1);
    Node *n4 = ct(4);
    Node *n2 = ct(2);
    Node *n3 = ct(3, n1, n2);
    Node *n6 = ct(6, ct(7), n4);

    Node *n5 = ct(5, n3, n6);
    //Node* n11 = ct(11);
    //Node* n9 = ct(9, ct(10), n11);
    //Node* root = ct(8, n5, n9);
    printTree(n5);
    auto res = getAllSeq(n5);
    cout << "Generated number of sequences: " << res.size() << endl;
    for (auto &&v : res)
    {
        for (auto &&e : v)
        {
            cout << e << " ";
        }
        cout << endl;
    }
}