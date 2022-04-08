#include "functions.h"

using namespace std;

struct Worker{
    string name, number, gender, date;
};

void create_file(const string& name){
    int num=8;            //number of workers
    Worker person;
    ofstream file(name, ios::binary);
    cout << "Enter number of workers: ";
    cin >> num;
    cin.ignore();
    while (num < 1){
        cout << "Enter a positive integer: ";
        cin >> num;
        cin.ignore();
    }
    for (int i = 0; i < num; ++i) {
        input_data(person);
        file.write((char*)&person, sizeof(Worker));
        cout << "pio";
    }
    file.close();
}

void input_data(Worker per){
    cout << "Full name: ";
    getline(cin, per.name);
    per.number = get_number();
    per.gender = get_gender();
    get_date(per);
}

string get_gender(){
    cout << "Gender (M/F): ";
    string gen;
    cin >> gen;
    while (true) {
        if (gen == "M" or gen == "m") return "male";
        else if (gen == "F" or gen == "f") return "female";
        cout << "Wrong input. Enter letter M for male or F for female: ";
        cin >> gen;
    }
}

string get_day(){
    string d;
    cout << "Day of birth: ";
    cin >> d;
    cin.ignore();
    while (!is_number(d)){
        cout << "Wrong input. Enter a number from 1 to 31: ";
        cin >> d;
        cin.ignore();
    }
    while (stoi(d) < 1 or stoi(d) > 31){
        cout << "Wrong input. Enter a number from 1 to 31: ";
        cin >> d;
        cin.ignore();
    }
    if (stoi(d) < 10) d = '0' + d;
    return d;
}

string get_month(){
    string m;
    cout << "Month of birth (number): ";
    cin >> m;
    cin.ignore();
    while (!is_number(m) and (stoi(m) < 1 or stoi(m) > 12)){
        cout << "Wrong input. Enter a number from 1 to 31: ";
        cin >> m;
        cin.ignore();
    }
    if (stoi(m) < 10) m = '0' + m;
    return m;
}

string get_year(){
    string y, year;
    cout << "Enter year of birth: ";
    cin >> y;
    cin.ignore();
    while (!is_number(y) and (stoi(y) < 1900 or stoi(y) > 2022)) {
        cout << "Wrong input. Try again: ";
        cin >> y;
        cin.ignore();
    }
    for (int i = int(log10(stoi(y))); i < 4; ++i) {
        year += '0';
    }
    year += y;
    return year;
}

void get_date(Worker per){
    string day, month, year;
    day = get_day();
    month = get_month();
    year = get_year();
    per.date = day + '.' + month + '.' + year;
    cout << per.date;
}

string get_number(){
    string num;
    cout << "Employee number (8 digits): ";
    cin >> num;
    while (num.length() != 8){                  //check if there are 8 chars
        cout << "Wrong length. Enter 8 digits: ";
        cin >> num;
    }
    while (!is_number(num)){                   //check if all chars are digits
        cout << "All chars have to be digits. Enter 8 digits: ";
        cin >> num;
    }
    return num;
}

void output_file(const string& name){
    Worker person;
    ifstream file(name, ios::binary);
    while (file.read((char*)&person, sizeof(Worker))){
        cout << setw(20) << person.name << "  " << person.date << "  ";
        cout << person.number << setw(10) << person.gender;
    }
}

bool is_number(const string& word){
    for (char i : word) {
        if (!isdigit(i)) return false;
    }
    return true;
}