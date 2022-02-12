#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
using namespace std;

/** Text from keyboard, until Alt+1 pressed
 * @return input text
 */
string get_text();
/** Creates new file with selected text
 * @param name name of file
 * @param text to put in the file
 */
void get_file(const string& name, const string& text);
/** Gets text from file
 * @param name name of file
 * @return text from the selected file
 */
string read_file(const string& name);
/** Splits text into lines
 * @param text selected text
 * @return vector with lines
 */
vector<string> split_lines(const string& text);
/** Puts len of the string in the beginning of each one
 * @param text started text
 * @return changed text
 */
string change_text(const string& text);
