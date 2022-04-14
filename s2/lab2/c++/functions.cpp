#include "functions.h"

using namespace std;

struct Date{
    char day[4];
    char month[4];
    int year;
};

struct Worker{
    char name[21];
    char number[9];
    char gender[7];
    Date birth;
};

void create_file(const string& name){
    ofstream file;
    string ch;
    cout << "Would you like to rewrite information (Y/N)? ";
    cin >> ch;
    while (ch != "Y" and ch != "y" and ch != "N" and ch != "n") {
        cout << "Wrong input. Enter 'Y' or 'N'. ";
        cin >> ch;
    }
    if (ch == "Y" or ch == "y") file.open(name, ios::binary);
    else file.open(name, ios::binary | ios::app);
    int num = get_amount();
    for (int i = 0; i < num; ++i) {
        Worker person = input_data();
        while (person.birth.year > 2002 or person.birth.year < 1962){
            cout << "Age of this person is out of range. Try again." << endl;
            person = input_data();
        }
        file.write((char*)&person, sizeof(Worker));
        cout << "Recorded" << endl;
    }
    file.close();
}

void create_sorted(const string& old, const string& under, const string& over){
    ifstream file(old, ios::binary);
    ofstream un(under, ios::binary), ov(over, ios::binary);
    Worker person{};
    while (file.read((char*)&person, sizeof(Worker))){
        if (person.birth.year <= 1982) ov.write((char*)&person, sizeof(Worker));
        else un.write((char*)&person, sizeof(Worker));
    }
    file.close();
    un.close();
    ov.close();
}

int get_amount(){
    string num;
    cout << "Enter number of workers to add: ";
    cin >> num;
    cin.ignore();
    while (!is_number(num) or stoi(num) < 1){
        cout << "Enter a positive integer: ";
        cin >> num;
        cin.ignore();
    }
    return stoi(num);
}

Worker input_data(){
    Worker per{};
    strcpy(per.name, get_name().c_str());
    strcpy(per.number, get_number().c_str());
    strcpy(per.gender, get_gender().c_str());
    strcpy(per.birth.day, get_day().c_str());
    strcpy(per.birth.month, get_month().c_str());
    per.birth.year = get_year();
    return per;
}

string get_name(){
    string name;
    cout << "Full name (up to 20 symbols): ";
    getline(cin, name);
    while(name.length() > 20){
        cout << "Too long. Try again: ";
        getline(cin, name);
    }
    return name;
}

string get_gender(){
    cout << "Gender (M/F): ";
    string gen;
    cin >> gen;
    cin.ignore();
    while (not(gen == "M" or gen == "m" or gen == "F" or gen == "f")) {
        cout << "Wrong input. Enter letter M for male or F for female: ";
        cin >> gen;
        cin.ignore();
    }
    if (gen == "M" or gen == "m") return "male";
    else if (gen == "F" or gen == "f") return "female";
}

string get_day(){
    string d;
    cout << "Day of birth: ";
    cin >> d;
    cin.ignore();
    while (!is_number(d) or stoi(d) < 1 or stoi(d) > 31){
        cout << "Wrong input. Enter a number from 1 to 31: ";
        cin >> d;
        cin.ignore();
    }
    if (stoi(d) < 10) d = '0' + d;
    return d+'.';
}

string get_month(){
    string m;
    cout << "Month of birth (number): ";
    cin >> m;
    cin.ignore();
    while (!is_number(m) or stoi(m) < 1 or stoi(m) > 12){
        cout << "Wrong input. Enter a number from 1 to 31: ";
        cin >> m;
        cin.ignore();
    }
    if (stoi(m) < 10) m = '0' + m;
    return m+'.';
}

int get_year(){
    string y;
    cout << "Enter year of birth: ";
    cin >> y;
    cin.ignore();
    while (!is_number(y) or stoi(y) < 1900 or stoi(y) > 2022) {
        cout << "Wrong input. Try again: ";
        cin >> y;
        cin.ignore();
    }
    return stoi(y);
}

string get_number(){
    string num;
    cout << "Employee number (8 digits): ";
    cin >> num;
    cin.ignore();
    while (num.length() != 8){
        cout << "Wrong length. Enter 8 digits: ";
        cin >> num;
        cin.ignore();
    }
    while (!is_number(num)){
        cout << "All chars have to be digits. Enter 8 digits: ";
        cin >> num;
        cin.ignore();
    }
    return num;
}

void output_file(const string& file_name){
    Worker person{};
    ifstream file(file_name, ios::binary);
    while (file.read((char*)&person, sizeof(Worker))){
        string name(person.name), day(person.birth.day), month=person.birth.month,
        year = to_string(person.birth.year), number(person.number), gender(person.gender);
        cout << setw(20) << name << ' ' << day << month << year << ' ' << number << setw(7) << gender << endl ;
    }
    file.close();
}

bool is_number(const string& word){
    for (char i : word) {
        if (!isdigit(i)) return false;
    }
    return true;
}