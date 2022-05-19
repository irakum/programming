#include <iostream>
#include <vector>
#pragma once

using namespace std;

class Equation {
    double a, b, c;
public:
    Equation();
    explicit Equation(vector<double>);
    static vector<double> inputABC();
    void getCoefs() const;
    void getEquation() const;
    bool hasSolution() const;
};
