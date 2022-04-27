#include "func.h"

using namespace std;

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