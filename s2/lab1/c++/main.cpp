#include "func.h"
using namespace std;

int main() {
    vector<string> input_text = get_text();
    get_file("Text.txt", input_text);
    vector<string> text = read_file("Text.txt");
    cout << "Text in the first file:" << endl;
    output("Text.txt");

    vector<string> second_text = change_text(text);
    get_file("Changed_text.txt", second_text);
    vector<string> output_text = read_file("Changed_text.txt");
    cout << "Text in the second file:" << endl;
    output("Changed_text.txt");
}
