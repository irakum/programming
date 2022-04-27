#include "Outputter.h"

void Outputter::printAll() {
    vector<Equation> equs = equations.getAll();
    cout << "List of equations:\n";
    for (int i = 0; i < equs.size(); ++i) {
        cout << i+1 << ") ";
        equs[i].getEquation();
        //equs[i].getCoefs();
        cout << ";\n";
    }
}

void Outputter::printNoSol() {
    cout << "Numbers of equations with no solution:\n";
    vector<int> nums = equations.getNoSol();
    for (int i = 0; i < nums.size()-1; ++i) {
        cout << nums[i] << ", ";
    }
    cout << nums.back() << '.';
}
