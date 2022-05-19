#include <iostream>
#include "func.h"
#include "BoolVector.h"

using namespace std;

int main() {
    BoolVector vec1(input_vec()), vec2(input_vec());
    BoolVector vec3 = vec1|vec2;
    cout << "Vector 3 (disjunction v1|v2):" << endl;
    print_vec(vec3);
    BoolVector vec4 = vec1^vec3;
    cout << "Vector 4 (exclusive or v1^v3):" << endl;
    print_vec(vec4);
    cout << "V4 is predecessor of V3: ";
    if (vec4.is_prev(vec3)) {cout << "True" << endl;}
    else {cout << "False" << endl;}
}
