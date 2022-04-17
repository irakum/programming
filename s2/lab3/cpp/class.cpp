#include "class.h"

using namespace std;

void Equation::setABC() {
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

bool is_double(string s){
    bool no_dot = true;
    if (s.empty() or s[0] == '.') {return false;}
    if (s[0] == '-'){
        s = s.substr(1);
        if (s.empty() or s[0] == '.') {return false;}
    }
    for (char c : s){
        if (!(isdigit(c) or (c == '.' and no_dot)))
        {return false;}
        no_dot = (c != '.');
    }
    return true;
}

bool is_number(const string& word){
    if (word.empty()) {return false;}
    for (char i : word) {
        if (!isdigit(i)) return false;
    }
    return true;
}

int get_number(){
    string num;
    cout << "Enter number of equations: "; cin >> num;
    cin.ignore();
    while(!is_number(num)){
        cout << "Enter a positive integer: "; cin >> num;
    }
    return stoi(num);
}

vector<Equation> get_vector(){
    vector<Equation> equs;
    int n = get_number();
    for (int i = 0; i < n; ++i) {
        Equation eq;
        eq.setABC();
        equs.push_back(eq);
    }
    return equs;
}

void print_equs(vector<Equation> vec){
    for (int i = 0; i < vec.size(); ++i) {
        cout << i+1 << ") ";
        vec[i].getEquation();
        //vec[i].getCoefs();
        cout << ";\n";
    }
}

vector<int> no_sol(vector<Equation> vec){
    vector<int> have;
    for (int i = 0; i < vec.size(); ++i) {
        if (!vec[i].hasSolution()) {have.push_back(i + 1);}
    }
    return have;
}

void print_res(vector<int> vec){
    for (int i = 0; i < vec.size()-1; ++i) {
        cout << vec[i] << ", ";
    }
    cout << vec.back() << '.';
}