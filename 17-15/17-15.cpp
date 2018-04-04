/******************************************************************************************************
* Seyedreza Najafi , March-2018
* Solution to the following problem from the "Cracking the Coding Interview" book, 6th edition
* 
* 17.15 Longest Word
*
******************************************************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class CompareStrings {
	// implement less
    public:
	bool operator()(const string& s1, const string& s2) {
		return (s1.length() > s2.length());
	}
};

class IsComposition {
public:
	bool check(string& str, vector<string>& v, int idx) {
		isCompResult = false;
		isComposition(str, v, idx);
		return isCompResult;
	}
    bool isCompResult;
private:

	void isComposition(string str, vector<string>& v, int idx) {
		if (isCompResult) { return; }
		for (int i = idx; i < v.size(); i++) {
			string& str1 = v[i];
            if(str1.length() > str.length()) {continue;}
			if (str.substr(0, str1.length()) == str1) {
				if (str1.length() == str.length()) { 
                    isCompResult = true; 
                    return; 
                }
				isComposition(str.substr(str1.length()), v, idx);
			}
		}
	}
};
string findLongestWord(vector<string>& v) {
	sort(v.begin(), v.end(), CompareStrings());
    for(auto& e:v){cout << e << " ";}
    cout <<endl;
	IsComposition  isComp;
	for (int i = 0; i < v.size(); i++) {
		if (isComp.check(v[i], v, i+1)) { return v[i]; }
	}
    return "";
}
int main(){
    vector<string> v = {"cat", "dog", "walk","walker", "dogwalker", "dognanacbtwalker", "dognanawalker", "banana", "nana"};
    cout << "The longest composit word is "<< findLongestWord(v) << endl;
}