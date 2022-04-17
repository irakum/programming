#include "class.h"
using namespace std;

int main() {
    vector<Equation> equations = get_vector();
    cout << "List of equations:\n";
    print_equs(equations);
    vector<int> no_solution = no_sol(equations);
    cout << "Numbers of equations with no solution:\n";
    print_res(no_solution);
}
