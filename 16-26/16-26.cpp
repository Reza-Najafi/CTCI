/******************************************************************************************************
* Seyedreza Najafi , March-2018
* Solution to the following problem from the "Cracking the Coding Interview" book, 6th edition
* 
* 16.26 Calculator
*
******************************************************************************************************/
#include <vector>
#include <iostream>
using namespace std;
class Calculator {
public:
    typedef enum 
    {ADD = 0, SUB, MUL, DIV, NON} OP;
    typedef pair<OP,double> Proc; 
    double calc(vector<Proc> & v) {
        lhs = 0;// the left hand side operand
        int procIdx = 0;
        // keep the current pair of operator and the rhs operand as pending since
        // we dont know if we need to update the rhs due to a mul/div commin next to it
        //pendingProc = v[procIdx];
        rhs = v[procIdx].second;
        operand = v[procIdx].first;
        while(++procIdx < v.size()) {

            auto currProc = v[procIdx];// is actually the next proc

            if(currProc.first == OP::ADD || currProc.first == OP::SUB) {
                applyPendingProc();// since there is +/- next, we can flush 
                //pendingProc = currProc;
                rhs = currProc.second;
                operand = currProc.first;
            } else {
                updatePendingProc(currProc);//just update the rhs
            }
        }
        applyPendingProc();
        return lhs;
    }   
    
private: 
    void applyPendingProc(){
        if(operand == OP::ADD){
            lhs += rhs;
        }
        if(operand == OP::SUB){
            lhs -= rhs; 
        }
        operand = OP::ADD;
        rhs = 0;
    }
    void updatePendingProc(Proc& p) {
        if(p.first == OP::DIV){
            rhs /= (double)p.second;
        }
        if(p.first == OP::MUL){
            rhs *= (double)p.second; 
        }
    }
    double lhs;// is actually the result
    double rhs;
    //Proc pendingProc;
    OP operand;

};

int main() {
    vector<Calculator::Proc> in = {make_pair(Calculator::OP::ADD,2) , make_pair(Calculator::OP::SUB,6), make_pair(Calculator::OP::SUB,7),
    make_pair(Calculator::OP::MUL,8),make_pair(Calculator::OP::DIV,2),make_pair(Calculator::OP::ADD,5),make_pair(Calculator::OP::DIV,3)};
    for(auto&p : in){
        switch(p.first){
            case Calculator::OP::ADD:
                cout << " + ";
            break;
            case Calculator::OP::SUB:
                cout << " - ";
            break;
            case Calculator::OP::DIV:
                cout << " / ";  
            break;
            case Calculator::OP::MUL:
                cout << " * ";
            break;
        }
        cout << p.second << " ";
    }
    Calculator cal;
    cout << endl << "Result " << cal.calc(in) << endl;
}