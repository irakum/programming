#include "func.h"
using namespace std;

vector<string> get_text() {
    cout << "Press Enter to go to the next line. Start new line, press Ctrl+X and then Enter to end typing."
        "\nEnter your text here:" << endl;
    vector<string> text;
    string line;
    cin.ignore();
    int end_of_text = 24;      // ctrl+x ascii code
    while (line[0] != end_of_text) {
        getline(cin, line);
        text.push_back(line);
    }
    text.pop_back();
    return text;
}

void get_first(const string& name) {
    ofstream new_file;
    string ch;
    cout << "Would you like to rewrite text (Y/N)? ";
    cin >> ch;
    while (ch != "Y" and ch != "y" and ch != "N" and ch != "n") {
        cout << "Wrong input. Enter 'Y' or 'N'. ";
        cin >> ch;
    }
    if (ch == "Y" or ch == "y") new_file.open(name);
    else {
        new_file.open(name, ios::app);
        new_file << '\n';
    }
    vector<string> text = get_text();
    for (int i = 0; i < text.size() - 1; ++i) {                    //add all lines except for the last one
        new_file << text[i] << '\n';
    }
    new_file << text.back();          //add last line(so the file woudn't end with '\n')
    new_file.close();
}

void get_second(const string& second, const string& first) {
    vector<string> text = read_file(first);
    vector<string> second_text = change_text(text);
    ofstream file(second);
    for (int i = 0; i < second_text.size() - 1; ++i) {                    
        file << second_text[i] << '\n';
    }
    file << second_text.back();                                  
    file.close();
}

vector<string> read_file(const string& name) {
    ifstream file(name);
    vector<string> text;
    string line;
    while (getline(file, line)) {
        text.push_back(line);
    }
    file.close();
    return text;
}

void output(const string& filename) {
    ifstream file(filename);
    string s;
    while (!file.eof()) {
        getline(file, s);
        cout << s << endl;
    }
    file.close();
}

vector<string> change_text(const vector<string>& text) {
    vector<string> new_text;
    for (auto& line : text) {
        string new_line = to_string(line.size());
        new_line += ' ' + line;                             
        new_text.push_back(new_line);
    }
    return new_text;
}