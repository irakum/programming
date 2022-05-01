#include "Equation.h"
#include "func.h"
#include <vector>
#pragma once
using namespace std;

class EqList {
    vector<Equation> all_eqs = {};
    vector<int> no_sol = {};
public:
    static vector<Equation> genEqList();
    void setEqList(vector<Equation>);
    void setNoSol(vector<int>);
    vector<int> genNoSol();
    vector<Equation> getAll();
    vector<int> getNoSol();
};

