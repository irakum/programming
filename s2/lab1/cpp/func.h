#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
using namespace std;

/** Text from keyboard, until Alt+1 pressed
 * @return input text
 */
vector<string> get_text();
/** Creates new file with selected text
 * @param name name of file
 * @param text to put in the file
 */
void get_file(const string& name, const vector<string>& text);
/** Gets text from file
 * @param name name of file
 * @return text from the selected file
 */
vector<string> read_file(const string& name);
/** Puts len of the string in the beginning of each one
 * @param text started text
 * @return changed text
 */
vector<string> change_text(const vector<string>& text);

void output(const vector<string>& text);