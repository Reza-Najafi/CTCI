#include <set>
#include <map>
template <typename Key, typename Value>
class Graph {

public:

    struct Node{
        Key k;
        Value v;
        std::set<Node*> s;
        Node(Key &key, Value& value): k(key),v(value) {}
        Node(Key &key): k(key) {}
    };
    typedef std::map<Key, Node*>  MapType;
    int createNode( Key& k,  Value& v) {
        if(m.find(k)!=m.end()) {return -1;}
        auto n = new Node(k,v);
        m.insert(make_pair(k,n));
        return 0;
    }
    int addEdge( Key& k1,  Key k2) {
        if(m.find(k1)==m.end()) {return -1;}
        if(m.find(k2)==m.end()) {return -2;}
        m[k1]->s.insert(m[k2]);
        m[k2]->s.insert(m[k1]);
        return 0;
    }
    typename MapType::iterator begin() {return m.begin();}
    typename MapType::iterator end() {return m.end();}
private:
    MapType m;
};
