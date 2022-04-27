#include "Equation.h"
#include "func.h"

using namespace std;

Equation::Equation() {
    string aa, bb, cc;
    cout << "Enter first coefficient: "; cin >> aa;
    cin.ignore();
    while (!is_double(aa)){
        cout << "Enter a valid float number: "; cin >> aa;
        cin.ignore();
    }
    cout << "Enter second coefficient: "; cin >> bb;
    cin.ignore();
    while (!is_double(bb)){
        cout << "Enter a valid float number: "; cin >> bb;
        cin.ignore();
    }
    cout << "Enter third coefficient: "; cin >> cc;
    cin.ignore();
    while (!is_double(cc)){
        cout << "Enter a valid float number: "; cin >> cc;
        cin.ignore();
    }
    a = stod(aa);
    b = stod(bb);
    c = stod(cc);
    cout << "Recorded\n";
}

void Equation::getCoefs() const {
    cout << '(' << a << ", " << b << ", " << c << ")";
}

void Equation::getEquation() const {
    cout << a << "x^2 + (" << b << ")x + (" << c << ") = 0";
}

bool Equation::hasSolution() const {
    double discr = b*b - 4*a*c;
    return (discr >= 0);
}
