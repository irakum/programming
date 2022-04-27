#include "EqList.h"

EqList::EqList() {
    all_eqs = genEqList();
    no_sol = genNoSol();
}

vector<Equation> EqList::genEqList() {
    vector<Equation> equs;
    int n = get_number();
    for (int i = 0; i < n; ++i) {
        Equation eq;
        equs.push_back(eq);
    }
    return equs;
}
vector<int> EqList::genNoSol() {
    vector<int> vec;
    for (int i = 0; i < all_eqs.size(); ++i) {
        if (!all_eqs[i].hasSolution()) {vec.push_back(i + 1);}
    }
    return vec;
}

vector<Equation> EqList::getAll() {return all_eqs;}

vector<int> EqList::getNoSol() {return no_sol;}