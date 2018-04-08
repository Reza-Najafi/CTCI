#include <iostream>
#include <map>
#include <string>
#include <queue>
using namespace std;

class WordTransformer
{
    struct Node {
        enum Visit { NOT_VISITED = 0, W1_VISITED, W2_VISITED};
        string w;// string
        Node* p;//previous node
        Visit v;//visited status
        Node(string& wrd){
            w = wrd;
            p = NULL;
            v = NOT_VISITED;
        };
    };
    map<string, Node*> m;
    map<string, vector<string>> var;
    bool oneAway(string& e1, string& e2) {
        if(e1.length() != e2.length()) return false;
        int count = 0;
        for(int i = 0; i < e1.length(); i++) {
            if(e1[i] != e2[i]) count++;
            if(count >=2 ) return false;
        }
        return (count == 1);
    }
    void createDict(vector<string>& v) {
        for(auto& e1:v) {
            auto n = new Node(e1);
            m.insert(make_pair(e1,n));
            vector<string> olist;
            var.insert(make_pair(e1,olist));
            for(auto& e2:v){
                if(oneAway(e1,e2)) {
                    var[e1].push_back(e2);
                }
            }
        }
    }
    string createPath(Node* n1, Node* n2) {
        string s;

        while(n1) {
            s.insert(0,"->");
            s.insert(0,n1->w);
            n1 = n1->p;
        }
        while(n2) {
            s.append(n2->w);
            s.append("->");
            n2 = n2->p;
        }
        return s;
    }
    //Do double sided BFS
    string searchPath(const string& w1, const string& w2) {
        if((m.find(w1)==m.end()) || (m.find(w2)==m.end())) return "";
        queue<Node*> q1; q1.push(m[w1]);
        queue<Node*> q2; q2.push(m[w2]);
        while(!q1.empty() || !q2.empty()) {
            if(!q1.empty()) {
                for(auto& w: var[q1.front()->w]) {
                    auto vistStatus = m[w]->v;
                    if( vistStatus == Node::NOT_VISITED) {
                        q1.push(m[w]);
                        m[w]->p = q1.front();
                        m[w]->v = Node::W1_VISITED;
                    } else if (vistStatus == Node::W2_VISITED) {
                        return createPath(q1.front(),m[w]);
                    }
                }
            }
            if(!q2.empty()) {
                for(auto& w: var[q2.front()->w]) {
                    auto vistStatus = m[w]->v;
                    if( vistStatus == Node::NOT_VISITED) {
                        q2.push(m[w]);
                        m[w]->p = q2.front();
                        m[w]->v = Node::W2_VISITED;
                    } else if (vistStatus == Node::W1_VISITED) {
                        return createPath(q2.front(),m[w]);
                    }
                }
            }
            if(!q1.empty()) { q1.front()->v = Node::W1_VISITED;q1.pop(); }
            if(!q2.empty()) { q2.front()->v = Node::W2_VISITED;q2.pop(); }


        }
        return "";
    }
    public:
    string lookup(vector<string>& v, const string& w1, const string& w2){
        createDict(v);
        return searchPath(w1,w2);
    }
};
int main() {
    vector<string> dict = {
        "DAMP","LAMP", "LIMP","LIME","LIKE","MIKE","PIKE","KIKE","BUMP","LUMP","MILE","KYLE","KALE","VALE","NAIL","TAIL","PALE",
        "TAKE","NAKE","MAKE","CAKE","NIKE","RIPE","KOLE","POLE","ROAR","TEAR","FEAR","CARE","TOOL","POOL","ROOL","FOOL","COOL",
        "NAIL","MALE","MILE","RAIL","NUMB","RAMP","ROPE","DOLE","RULE","JEWL","GALE","TALE","NOAM","PAIR","CHAR","TAAR","MARS",
        "RAIN","PURS","CURS","TRUE","PURE","CURE","FORE","LORE","NAND","LAND","POND","RAND","LAMB","MANE","JANE","CANE","LOBE"
    };

    WordTransformer wt;
    cout << wt.lookup(dict, "DAMP","CANE");
}
