#include "functions.h"

using namespace std;

int main() {
    create_file("All.txt");
    cout << "List of all workers:" << endl;
    output_file("All.txt");
    create_sorted("All.txt", "Under40.txt", "Over40.txt");
    cout << "List of workers under 40:" << endl;
    output_file("Under40.txt");
    cout << "List of workers over 40:" << endl;
    output_file("Over40.txt");
}
