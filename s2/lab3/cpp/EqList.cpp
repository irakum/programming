#include "EqList.h"

vector<Equation> EqList::genEqList() {
    vector<Equation> equs;
    int n = get_number();
    for (int i = 0; i < n; ++i) {
        Equation eq(Equation::inputABC());
        cout << "Recorded" << endl;
        equs.push_back(eq);
    }
    return equs;
}

vector<int> EqList::genNoSol() {
    vector<int> vec;
    for (int i = 0; i < all_eqs.size(); ++i) {
        if (!all_eqs[i].hasSolution()) vec.push_back(i + 1);
    }
    return vec;
}

void EqList::setEqList(vector<Equation> vec) {all_eqs = vec;}

void EqList::setNoSol(vector<int> vec) {no_sol = vec;}

vector<Equation> EqList::getAll() {return all_eqs;}

vector<int> EqList::getNoSol() {return no_sol;}