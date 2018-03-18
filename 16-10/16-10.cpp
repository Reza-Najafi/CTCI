
#include <iostream>
#include <vector>

using namespace std;
class MostLivingPeople {
public:
    pair<int,int> getMostLivingYear(pair<vector<int>, vector<int>>& v) {
        sort(v.first);
        vector<int> y(v.first.size(),0);
        int i = 0;
        for(auto& e:y){ e = ++i;}
        for(auto& e:v.second){
            int idx = lowerBound(v.first,e);
            if(idx >=0){
                while(idx < y.size() ){y[idx++]--;}
            }
        }
        int max = 0;
        int retIdx = -1;
        for(int i = 0;i< y.size(); i++){
            if(y[i]>max){
                max = y[i];
                retIdx = i;
            }
        }
        return make_pair(v.first[retIdx],max);
    }

    int lowerBound(vector<int>& a , int v) {
        return lowerBound(a,0,a.size()-1,v);
    }

    int lowerBound(vector<int>& a , int l, int h, int v){
        if(a[h]<v){return -1;}
        int mid = (l+h)/2;
        if(mid-1>=0){
            if(  a[mid]>=v && a[mid-1]<v){
                return mid;
            }
        }else {
            if(  a[mid]>=v ) {
                return mid;
            }
        }
        int idx = lowerBound(a,l,mid-1,v);
        if(idx != -1){
            return idx;
        }
        idx= lowerBound(a,mid+1,h,v);
        if(idx != -1){
            return idx;
        }
        return -1;
    }
    void sort(vector<int>& a){
        partition(a,0,a.size()-1);
    }

private:

    // return : pivot index
    int partition(vector<int>&a , int l, int h){
        if(l>=h){return -1;}
        int p = a[h]; // pivot value
        int i = l, j = h-1;
        int pid = h;// pivot index
        while(i<j){
            if(a[i]<p){
                i++;
            } else {
                // a[i] >= p
                while(i < j && a[j] >=p){
                    j--;
                }
                if( i >= j) {break;}
                swap(a[i],a[j]);
                pid = j;
                i++;j--;
            }
        }
        while((pid-1)>=i && a[pid-1]>=p){pid--;}
        swap(a[pid],a[h]);
        partition(a,l,pid-1);
        partition(a,pid+1,h);
        return pid;
    }
};

int main()
{
    vector<int> test = {-10,10,1,4,3,7,1,9,7,0,4,67,13,2,1,0};
    vector<int> birth = {21,12, 25,1,10, 29,3 ,19,9 , 4 ,8,20 };
    vector<int> death = {45,14, 56,9,39, 67,28,56,45,18,28,38};
    MostLivingPeople mlp;
    mlp.sort(test);
#if defined TEST
    for(auto&i:test){
        cout << i<<" , ";
    }
    cout << endl;
    int val = 5;
    cout << "Upper bound of "<< val << " is at index "<< mlp.lowerBound(test,val)<< endl;
#endif
    auto d = make_pair(birth, death);
    auto res = mlp.getMostLivingYear(d);
    cout << "max number of years " << res.first << " occured "<<res.second<< " times"<< endl;
    return 0;
}
