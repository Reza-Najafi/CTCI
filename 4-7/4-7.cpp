/******************************************************************************************************
* Seyedreza Najafi , March-2018
* Solution to the following problem from the "Cracking the Coding Interview" book, 6th edition
* 
* 4.7 Build Order
*
******************************************************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;
pair<vector<char>, bool> build_order(vector<char> proj, vector<pair<char, char>>& deps) {
	map<char, set<char>> m;
	// building the map of dependencies
	for (auto&& d : deps) {
		if (m.find(d.second) == m.end()) {
			set<char> v = { d.first };
			m.insert(make_pair(d.second, v));
		}
		else {
			m[d.second].insert(d.first);
		}
	}

	// go through the projects and check which ones are independent (not in the dep map)
	vector<char> res;
	while (!proj.empty()) {
		int removedProjCounts = 0;
		// every round we go through the projects there should be at least a single independent project,
		int sz = proj.size();
		for (int i =sz-1; i >=0 ; --i ) {
		    auto& p = proj[i];
			// remove the independent (not found in the dep map) projects form the proj
			if (m.find(p) == m.end()) {
				// found an independent project, insert it into the result sequence
				res.push_back(p);
				removedProjCounts++;
				// go through dep and remove the dependecies
				for (auto&& d : m) {

					//if the to-be-deleted project is in the map of dependencies of any project remove it
					auto it = d.second.find(p);
					if (it != d.second.end()) {
						d.second.erase(it);
					}
					if (d.second.empty()) {
						m.erase(m.find(d.first));
					}
				}

				// remove from the proj from the proj dependencies
				proj.erase(proj.begin()+i);
			}
		}
		if (removedProjCounts == 0) { return make_pair(res, false); }
	}
	return make_pair(res, true);
}

void test (vector<char> & p, vector<pair<char,char>>& dep) {
    auto res = build_order(p,dep);
    cout << "List of projects\n";
    for(auto&& proj: p) cout << proj << " ";
    cout << endl;
    cout << "List of dependencies\n";
    for(auto&& d: dep) cout <<"( "<< d.first << " " << d.second << " ) ";
    cout << endl;
    if(!res.second) { cout << "Could not find a valid build order\n"; return ;}
    cout << "The build order: \n";
    for(auto&& proj: res.first) cout << proj << " ";
    cout << endl << endl;
}

int main() {
    vector<char> p1 = {'a','b','c','d','e','f'};
    vector<pair<char,char>> dep1 = {make_pair('a','d'),make_pair('f','b'),make_pair('b','d'),make_pair('f','a'),make_pair('d','c')};
    test(p1,dep1);
    vector<char> p2 = {'a','b','c','d','e','f'};
    vector<pair<char,char>> dep2 = {make_pair('c','f'), make_pair('a','d'),make_pair('f','b'),make_pair('b','d'),make_pair('f','a'),make_pair('d','c')};
    test(p2,dep2);
}