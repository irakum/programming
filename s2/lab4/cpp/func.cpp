#include "func.h"

bool is_bool(string line){
    for (char c : line) {
        if (c != '0' and c != '1'){return false;}
    }
    return true;
}

string input_vec(){
    string vec;
    cout << "Enter the vector:" << endl;
    cin >> vec;
    cin.ignore();
    while (!is_bool(vec)){
        cout << "All symbols have to be 0 or 1. Try again:" << endl;
        cin >> vec;
        cin.ignore();
    }
    cout << "Recorded" << endl;
    return vec;
}

void print_vec(BoolVector vec){
    bool* num = vec.get_vec();
    for (int i = 0; i < vec.get_size(); ++i) {cout << num[i];}
    cout << endl;
}