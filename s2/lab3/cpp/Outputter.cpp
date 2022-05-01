#include "Outputter.h"

void Outputter::printAll() {
    vector<Equation> equs = equations.getAll();
    cout << "List of equations:"<<endl;
    for (int i = 0; i < equs.size(); ++i) {
        cout << i+1 << ") ";
        equs[i].getEquation();
        //equs[i].getCoefs();
        cout << ";"<<endl;
    }
}

void Outputter::printNoSol() {
    vector<int> nums = equations.getNoSol();
    if (nums.empty()) cout << "All equations have at least one solution." << endl;
    else {
        cout << "Numbers of equations with no solution:" << endl;
        for (int i = 0; i < nums.size() - 1; ++i) {
            cout << nums[i] << ", ";
        }
        cout << nums.back() << '.' << endl;
    }
}

void Outputter::setOut() {
    equations.setEqList(EqList::genEqList());
    equations.setNoSol(equations.genNoSol());
}