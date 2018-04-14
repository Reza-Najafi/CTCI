#include <map>
#include <string>

class Trie {
    public:
    struct TrieNode {
        std::map<char,TrieNode*> m;
        int isWord;
    };
    void insert(std::string& w) {
        auto n = &root;
        for(auto& e: w) {
            if( n->m.find(e) == n->m.end()) {
                auto newNode = new TrieNode();
                n->m.insert(std::make_pair(e,newNode));
                n = newNode;
            } else {
                n = n->m[e];
            }
        }
        n->isWord = true;
    }
    bool lookup(std::string& w) {
        auto n = &root;
        for(auto&e : w) {
            if(n->m.find(e) == n->m.end()) return false;
            n = n->m[e];
        }
        return true;
    }
    TrieNode* getLastNode(std::string& w) {
        auto n = &root;
        for(auto& e: w) {
            if(n->m.find(e) == n->m.end()) return NULL;
            n = n->m[e];
        }
        return n;
    }
    TrieNode root;
};
