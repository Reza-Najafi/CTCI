#include <vector>
#include <map>
#include <iostream>
using namespace std;


pair<int,int> maxEqualSubSequence(vector<int> & v) {
	int zcount = 0, ocount = 0;
	map<int, int> m; // first diff, second index
	vector<int> diffs(v.size());
	for(int i = 0; i < v.size(); i++) {
		zcount += (v[i] == 0) ? 1 : 0;
		ocount += (v[i] == 1) ? 1 : 0;
		int diff = ocount - zcount;
		diffs[i] = diff;
		if(m.find(diff) == m.end()) m.insert(make_pair(diff,i));
	}
	cout << "Diffs : ";
	for(auto& e:diffs) { cout << e<< " ";}
	cout << endl;
	int sz = diffs.size();
	for(int i = sz -1 ; i >= 0 ; --i) {
		auto it = m.find(-diffs[i]);
		if( it != m.end()) {
			if(it->second < i) 
				return make_pair(it->second ,i);
		}
	}
	return make_pair(-1,-1);
}

int main() {
    vector<int> v = {0,1,1,0,0,0,0, 1,1,1, 0,1,1,0,1,0,1,0,1, 0, 1,1,1, 0,1};
    cout << "Input : ";
	for(auto& e:v) { cout << e<< " ";}
	cout << endl;
	auto r = maxEqualSubSequence(v);
	cout << r.first << " "<< r.second << endl;
}