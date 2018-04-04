#include <iostream>
#include <string>
#include <math.h>
using namespace std;
string bin2str(double x)
{
    string s = "0.";
    double h = 0.5;
    const double thresh = 1.0/pow(10,7);
    while(x>thresh) {
        if(x-h >= 0) {
            s.push_back('1');
            x -= h;
        } else {
            s.push_back('0');
        }
        h /= 2.0;
        if(s.size() >= 32) break;
    }
    return ((x > thresh) ? "ERROR": s);
}

int main() {
    double x = 0.2;
    cout << bin2str(x) << endl;
}
