/******************************************************************************************************
* Seyedreza Najafi , March-2018
* Solution to the following problem from the "Cracking the Coding Interview" book, 6th edition
* 
* 10.2 Group Anagrams
*
******************************************************************************************************/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#if 0 // Solution#1 The in-place solution that uses a complete sort based on the histograms of each string
void create_hist(string& str, int (&arr)[256]) {
    for(int &i: arr){
        i = 0;
    }
    for(auto &&c: str){
        arr[c]++;
    }
}

void insertion_sort(vector<int[256]>& v, vector<int>& a, int i){
    for(int k = 1; k < a.size(); k++) {
        int currPtr = k-1;
        int tmp = a[k];
        while(currPtr >=0 && v[a[currPtr]][i] > v[a[k]][i]){
            //a[currPtr+1] = a[currPtr];
            currPtr--;
        }
        if(currPtr+1 == k){continue;}
        a.erase(a.begin()+k);// remove the kth element
        a.insert(a.begin()+currPtr+1,tmp);// insert it at currPtr+1 (it becomes the currPtr+1)
        //a[currPtr+1]=tmp;
    }
}

void selection_sort(vector<int[256]>& v, vector<int>& a, int i){
    for(int k= 0; k<a.size(); k++){
        // when referring to elements in the v use the index mapping of a
        int min = v[a[k]][i];
        int minId = k;
        for(int j = k; j < a.size(); j++) {
            if(v[a[j]][i] < min) {
                min = v[a[j]][i];
                minId = j;
            }
        }
        // we need a stable selection sort , as a result we can not simply 
        // swap the elements we need to "insert" the minimum before the kth 
        // element, and erase the minimum from where it was
        int tmp = a[minId];
        a.erase(a.begin()+minId);
        a.insert(a.begin()+k,tmp);
    }
}

void sort_hist(vector<int[256]>& v, vector<int>& a){
    // sort the v using all elements in the histogram, one at a time
    for(int i = 0; i < 256; i++) {
        insertion_sort(v,a,i);
    }
}

void print_hist(int (&a)[256]) {
    // print just the small letters
    for(int i = 97; i < 123; i++) {
        cout << a[i] << " , ";
    }
    cout << endl;
}

void gruop_anagrams(vector<string>& a) {
    size_t N = a.size();
    vector<int[256]> arrHist(N);
    vector<int> id(N);
    for(auto& str:a){
        cout << str << " , ";
    }
    cout << endl;
    for(int i = 0; i < N; i++) {
        create_hist(a[i], arrHist[i]);
        //cout << "Input string "<< a[i] <<endl;
        //print_hist(arrHist[i]);
        id[i] = i;
    }
    //cout << endl;
    sort_hist(arrHist,id);
    cout << "index mapping array :\n";
    for(auto e : id){
        cout << e << " , ";
    }
    cout << endl;
    //go through all cycles in the permutation 
    for(int i = 0; i < a.size(); i++)
    {
        // don't go over permutations which have been used 
        // element is in the right place and asscoiated cycle
        // has been traveresed fully
        if(id[i] == -1) {continue;}
        int dst = i;
        int src = id[dst];
        string tmp = a[i];
        while(src != i){
            a[dst] = a[src];
            dst = src;
            src = id[dst]; 
            id[dst] = -1;//mark the permutation when it is used
        }
        a[dst] = tmp;
    }
}
#endif // Solution#1 The in-place solution that uses a complete sort based on the histograms of each string



#if 0 // Solution#2 The naive solution, Using the STL sort and overwritten compare function
#include <algorithm>
struct  {
    // define a greater operator so that if a= isanagram(b) neither is greater than the other
    bool operator()(string a, string b)
    {
        if (a.length() > b.length()) {
            return true;
        } 
        if(a.length() < b.length()) {
            return false;
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        if(a>b){return true;}
        return false;
        
    }
} compareAnagrams;

void gruop_anagrams(vector<string>& v){
    sort(v.begin(), v.end(), compareAnagrams);
}
#endif // Solution#2 Solution#3 The naive solution, Using the STL sort and overwritten compare function




#if 1 // Solution#3 The in-place solution using a map for "bucketing" the anagrams
#include <map>
#include <algorithm>
void gruop_anagrams(vector<string>& v){
    map<string, vector<int>> m;
    for(int i = 0; i < v.size(); i++) {
        string toBeSorted = v[i];
        sort(toBeSorted.begin(), toBeSorted.end());    
        if(m.find(toBeSorted) == m.end()) {
            vector<int> v;
            v.push_back(i);
            m.insert(make_pair(toBeSorted,v));
        } else {
            m[toBeSorted].push_back(i);
        }
    }
    
    vector<int> id(v.size());
    int i = 0;
    for(auto& e : m){
        for(auto& val: e.second) {
            id[i++] = val;    
        }
    }
    cout << "The permutation indexes: \n";
    for(auto& e: id) {
        cout << e <<" , ";
    }
    cout<<endl;
    // Go through permutation
    for(int i = 0; i < id.size(); i++) {
        if(id[i] == -1) {continue;}
        int dst = i;
        int src = id[i];
        auto tmp = v[dst];
        while(src != i){
            v[dst] = v[src];
            dst = src;
            src = id[dst];
            id[dst] = -1;
        }
        v[dst] = tmp;
    }
}
#endif // Solution#3 The in-place solution using a map for "bucketing" the anagrams


int main()
{
    vector<string> str = { "abb", "abc", "cba", "bca", "bba", "c", "a", "aa", 
    "b", "bacd","abb", "abc", "dcba", "dbx","cba", "dca","bca", "bba", "xbd" ,
    "abcd", "c"};
    gruop_anagrams(str);
    for(auto& s : str) {
        cout << s << " , ";
    }
    return 0;
}


