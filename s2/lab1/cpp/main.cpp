#include "func.h"
using namespace std;

int main() {
    string input_text = get_text();
    get_file("Text.txt", input_text);
    string text = read_file("Text.txt");
    cout << "Text in the first file:" << endl << text << endl;

    string second_text = change_text(text);
    get_file("Changed_text.txt", second_text);
    string output_text = read_file("Changed_text.txt");
    cout << "Text in the second file:" << endl << second_text << endl;
}
