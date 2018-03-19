#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class SmallestDiffernce {
public:
    pair<int, int> findPairWithSmallestDiff(vector<int>& v1,vector<int>& v2){
        sort(v1.begin(), v1.end());
        pair<int , int > p;
        int minDiff;
        for(int i = 0; i < v2.size(); i++){
            int idx = getSmallestDiffIdx(v1, v2[i]);
            int diff = abs(v1[idx]-v2[i]);
            if(i == 0 || diff < minDiff ){
                minDiff = diff;
                p.first = idx;
                p.second = i;
            }
        }
        return p;
    }

    int getSmallestDiffIdx(vector<int>& a,int v) {
        int idx = getSmallestDiffIdx(a,0,a.size()-1, v);
        if(idx != -1) {
            return idx;
        } else {
            return  (a.size()-1);
        }
    }

    int getSmallestDiffIdx(vector<int>& a,int l, int h, int v) {
        if (l > h){
            return -1;
        }
        int mid = (l+h)/2;


        if(mid-1>=0){
            if(a[mid] >= v  && a[mid-1] < v ) {
                if(abs(a[mid]-v) < abs(a[mid-1]-v)){
                    return mid;
                } else {
                    return mid-1;
                }
            }
        } else {
            if(a[mid] >= v ) {
                return mid;
            }
        }

        int idx = getSmallestDiffIdx(a,l,mid-1,v);
        if(idx != -1){
            return idx;
        }
        idx = getSmallestDiffIdx(a,mid+1,h,v);
        return idx;
    }
};

int main()
{
    SmallestDiffernce smd;
#if TEST
    vector<int> v ={1,3,7,9,90,900,1000};
    int val = 91;
    int idx = smd.getSmallestDiffIdx(v,val);
    cout << "closes value to " << val <<" is "<< v[idx]<< endl;
#endif
    vector<int> v1 ={1000, 1,7, 9, 3,900,10, 90};
    vector<int> v2 ={64,765,82,30,12,398,500};
    auto p = smd.findPairWithSmallestDiff(v1,v2);
    cout << "closest pair is "<< v1[p.first]<< " , "<<v2[p.second] << endl;
    return 0;
}
