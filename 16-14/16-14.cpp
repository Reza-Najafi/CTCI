
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <tuple>
using namespace std;
class BestLine {
public:
    typedef  pair<int,int> Point;
    typedef  tuple<int, float, float> Line;
    //typedef  float InfLine;

    void insert(vector<Point>& vp) {
        int sz = vp.size();
        for(int i = 0; i < sz; i++) {
            for(int j = i+1; j < sz; j++) {
                //find the slope of the vp[i] vp[j]
                // enter the pair into the map
                float s = slope(vp[i], vp[j]);

                if(!isinf(s)) {
                    float b = vp[i].second - s*vp[i].first;
                    auto line = make_tuple(1,s,b);
                    if(m.find(line) == m.end()) {
                        set<Point> * v = new set<Point>;
                        m.insert(make_pair(line,v));
                    }
                    m[line]->insert(vp[i]);
                    m[line]->insert(vp[j]);
                } else {
                    float b = -vp[i].first;
                    auto line = make_tuple(0,1, b);
                    if(m.find(line) == m.end()) {
                        set<Point> * v = new set<Point>;
                        m.insert(make_pair(line,v));
                    }
                    m[line]->insert(vp[i]);
                    m[line]->insert(vp[j]);
                }
            }
        }
    }

    set<Point>* find(){
        int max = 0;
        set<Point>* ps = m.begin()->second;
        for(auto& s: m){
            if(s.second->size() > max){ max = s.second->size(); ps = s.second;}
        }
        return ps;
    }

private:
    typedef map<Line,set<Point>*> MapType;
    MapType m;

    float slope(Point& p1, Point&p2){
            return ((float)p2.second - (float)p1.second)/((float)p2.first - (float)p1.first);
    }
};



int main()
{
    BestLine bl;
    vector<BestLine::Point> v = {make_pair(3,8), make_pair(0,0),make_pair(-1,1), make_pair(1,2), make_pair(2,5),
    make_pair(3,6), make_pair(1,3), make_pair(1,4), make_pair(1,5), make_pair(4,8), make_pair(5,10)};
    bl.insert(v);
    auto out = bl.find();
    for(auto& p: *out){
        cout << "( " << p.first << " , "<< p.second << " ) ";
    }
    cout << endl;

    return 0;
}
