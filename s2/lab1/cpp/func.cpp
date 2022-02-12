#include "func.h"
using namespace std;

string get_text(){
    cout << "Press Enter to go to the next line. Start new line, press Alt+1 and then Enter to end typing."
            "\nEnter your text here:\n";
    string text;
    string line;
    int end_of_text = 1;      // ctrl+c ascii code
    while (int(line[0]) != end_of_text){
        getline(cin, line);
        text += line + "\n";
    }
    text = text.substr(0, text.size()-3);
    return text;
}

void get_file(const string& name, const string& text){
    ofstream new_file(name);
    new_file << text;
    new_file.close();
}

string read_file(const string& name){
    ifstream file(name);
    string text, line;
    while (getline(file, line)){
        text += line + "\n";
    }
    file.close();
    text = text.substr(0, text.size()-1);
    return text;
}

vector<string> split_lines(const string& text){
    vector<string> lines;
    int last = 0;
    for (int i = 0; i < text.size(); ++i) {                          // separates text from enter to enter
        if (text[i] == '\n') {
            string line = text.substr(last, i-last);
            last = i + 1;
            lines.push_back(line);
        }
    }
    lines.push_back(text.substr(last, text.size()-last));    // adds last line
    return lines;
}

string change_text(const string& text){
    string new_text;
    vector<string> lines = split_lines(text);
    for (auto & line : lines) {
        string new_line = to_string(line.size());       // new line with len of started one
        new_line += ' ' + line;                             // add text from started one
        new_text += new_line + '\n';
    }
    new_text = new_text.substr(0, new_text.size()-1);
    return new_text;
}