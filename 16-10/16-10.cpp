
#include <iostream>
#include <vector>
#include <map>
#include <vector>


using namespace std;
class MostLivingPeople {
public:
    void getMostLivingYear(pair<vector<int>, vector<int>>& v) {

    }

    int upperBound(vector<int>& a , int v) {
        return upperBound(a,0,a.size()-1,v);
    }

    int upperBound(vector<int>& a , int l, int h, int v){
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
        int idx = upperBound(a,l,mid-1,v);
        if(idx != -1){
            return idx;
        }
        idx= upperBound(a,mid+1,h,v);
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
    vector<int> birth = {1,3,6 ,8 ,19,37,65};
    vector<int> death = {6,8,18,28,56,39,99};
    MostLivingPeople mlp;
    mlp.sort(test);
    for(auto&i:test){
        cout << i<<" , ";
    }
    cout << endl;
    int val = 5;
    cout << "Upper bound of "<< val << " is at index "<< mlp.upperBound(test,val)<< endl;
    return 0;
}
