#include "Equation.h"
#include "func.h"

using namespace std;

void Equation::setABC() {
    vector<string> coefs = {"0", "0", "0"};
    coefs = input_coefs(coefs);
    while (coefs[0] == "0" and coefs[1] == "0"){
        cout << "Invalid input. Both first and second coefficients can't be 0. Try again." << endl;
        coefs = input_coefs(coefs);
    }
    a = stod(coefs[0]);
    b = stod(coefs[1]);
    c = stod(coefs[2]);
    cout << "Recorded" << endl;
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
