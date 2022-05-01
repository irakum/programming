#include <iostream>
#include <vector>
#pragma once

using namespace std;

class Equation {
    double a=0, b=0, c=0;
public:
    void setABC();
    void getCoefs() const;
    void getEquation() const;
    bool hasSolution() const;
};
