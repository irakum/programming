#include "func.h"
using namespace std;

int main() {
    get_first("Text.txt");
    cout << "Text in the first file:" << endl;
    output("Text.txt");

    get_second("Changed_text.txt", "Text.txt");
    cout << "Text in the second file:" << endl;
    output("Changed_text.txt");
}