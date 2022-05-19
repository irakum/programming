#include "func.h"

using namespace std;

bool is_double(string s){
    bool no_dot = true;
    if (s.empty() or s[0] == '.') return false;
    if (s[0] == '-'){
        s = s.substr(1);
        if (s.empty() or s[0] == '.') return false;
    }
    for (char c : s){
        if (!(isdigit(c) or (c == '.' and no_dot))) return false;
        if (c=='.') no_dot = false;
    }
    return true;
}

bool is_number(const string& word){
    if (word.empty()) return false;
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
        cin.ignore();
    }
    return stoi(num);
}

vector<string> input_coefs(){
    vector<string> res;
    for (int i = 0; i < 3; ++i) {
        string coef;
        printf("Enter %i coefficient: ", i+1);
        cin >> coef;
        while (!is_double(coef)){
            cout << "Enter a valid float number: ";
            cin >> coef;
        }
        res.push_back(coef);
    }
    return res;
}