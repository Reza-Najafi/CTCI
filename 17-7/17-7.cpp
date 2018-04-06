#include "utilities/Graph.h"
#include <iostream>
#include <string>
#include <queue>
using namespace std;

typedef vector<pair<string,string>> NamePairs;
typedef map<string,int> NameFreq;
typedef Graph<string, int> GraphType;

int bfs(GraphType::Node* node, set<GraphType::Node*>& visited) {
    if(visited.find(node) != visited.end()) {return 0;}
    queue<GraphType::Node*> q;
    q.push(node);
    cout << ">>>> Started BFS ";
    int count = 0;
    while(!q.empty()) {
        count += q.front()->v;
        cout << " " << q.front()->k << " ";
        for(auto& n: q.front()->s ) {
            if(visited.find(n) == visited.end()) {
                q.push(n);
            }
        }
        visited.insert(q.front());
        q.pop();
    }
    cout << endl;
    return count;
}


NameFreq traverse(GraphType& g) {
    set<GraphType::Node*> visited;
    NameFreq counts;
    for(auto& e: g) {
        auto c = bfs(e.second, visited);
        if(c != 0)
            counts.insert(make_pair(e.second->k,c));
    }
    return counts;
}


GraphType& constructGraph(NameFreq& nf, NamePairs& np) {
    auto g = new Graph<string, int>();
    for(auto&e : np) {
        g->createNode(e.first, nf[e.first]);
        g->createNode(e.second, nf[e.second]);
        g->addEdge(e.first, e.second);
    }
    return *g;
}

NameFreq process(NameFreq& nf, NamePairs& np) {
    auto g = constructGraph(nf,np);
    return traverse(g);
}

int main() {
    NamePairs np = {make_pair("John","Jon"), make_pair("Chris", "Kris"),
                    make_pair("Johnny", "Joan"), make_pair("Jon","Joan"),
                    make_pair("Jake", "Jack"), make_pair("Christopher", "Christ"),
                    make_pair("Christ","Kris"),make_pair("Jacky","Jake")
    };
    NameFreq nf = {make_pair("John",5) , make_pair("Jon",3), make_pair("Chris", 2),
                    make_pair("Kris",1), make_pair("Johnny",6),make_pair("Joan",4),
                    make_pair("Jake",7), make_pair("Jack",2), make_pair("Christopher",3),
                    make_pair("Christ",2), make_pair("Jacky",9)
    };

    auto ret = process(nf,np);
    for(auto& e: ret) {
        cout << e.first << " : " << e.second << endl;
    }
}
