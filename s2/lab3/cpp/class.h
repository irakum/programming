#include <iostream>
#include <vector>
using namespace std;

class Equation {
    double a = 0, b = 0, c = 0;
public:
    void getCoefs() const;
    void getEquation() const;
    void setABC();
    bool hasSolution() const;
};

bool is_double(string s);
int get_number();
bool is_number(const string& word);
vector<Equation> get_vector();
void print_equs(vector<Equation> vec);
vector<int> no_sol(vector<Equation> vec);
void print_res(vector<int> vec);
