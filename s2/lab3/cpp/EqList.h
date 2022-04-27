#include "Equation.h"
#include "func.h"
#include <vector>
#pragma once
using namespace std;

class EqList {
    vector<Equation> all_eqs;
    vector<int> no_sol;
public:
    EqList();
    static vector<Equation> genEqList();
    vector<int> genNoSol();
    vector<Equation> getAll();
    vector<int> getNoSol();
};

