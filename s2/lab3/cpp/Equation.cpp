#include "Equation.h"
#include "func.h"

using namespace std;


Equation::Equation() {
    a = 0;
    b = 0;
    c = 0;
}

Equation::Equation(vector<double> vec) {
    a = vec[0];
    b = vec[1];
    c = vec[2];
}


vector<double> Equation::inputABC() {
    vector<string> coefs = input_coefs();
    while (coefs[0] == "0" and coefs[1] == "0"){
        cout << "Invalid input. Both first and second coefficients can't be 0. Try again." << endl;
        coefs = input_coefs();
    }
    vector<double> res;
    res.reserve(3);
for (int i = 0; i < 3; ++i) {
        res.push_back(stod(coefs[i]));
    }
    return res;
}

void Equation::getCoefs() const {
    cout << '(' << a << ", " << b << ", " << c << ")";
}

void Equation::getEquation() const {
    //printf("(%f)x^2 + (%f)x + (%f) = 0", a, b, c);
    cout << "(" << a << ")x^2 + (" << b << ")x + (" << c << ") = 0";
}

bool Equation::hasSolution() const {
    double discr = b*b - 4*a*c;
    return (discr >= 0);
}
