#include "func.h"
using namespace std;

vector<string> get_text(){
    cout << "Press Enter to go to the next line. Start new line, press Alt+1 and then Enter to end typing."
            "\nEnter your text here:\n";
    vector<string> text;
    string line;
    int end_of_text = 1;      // alt+1 ascii code
    while (int(line[0]) != end_of_text){
        getline(cin, line);
        text.push_back(line);
    }
    text.pop_back();
    return text;
}

void get_file(const string& name, const vector<string>& text){
    ofstream new_file(name);
    for (int i = 0; i < text.size()-1; ++i) {
        new_file << text[i] << '\n';
    }
    new_file << text.back();
    new_file.close();
}

vector<string> read_file(const string& name){
    ifstream file(name);
    vector<string> text;
    string line;
    while (getline(file, line)){
        text.push_back(line);
    }
    file.close();
    return text;
}

void output(const vector<string>& text){
    for (const auto& line: text) {
        cout << line << endl;
    }
}

vector<string> change_text(const vector<string>& text){
    vector<string> new_text;
    for (auto & line : text) {
        string new_line = to_string(line.size());       // new line with len of started one
        new_line += ' ' + line;                             // add text from started one
        new_text.push_back(new_line);
    }
    return new_text;
}