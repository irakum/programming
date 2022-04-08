#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

/**Text from keyboard, until Ctrl+X pressed
* @return input text
*/
vector<string> get_text();
/** Creates new file with selected text
* @param name name of file
*/
void get_first(const string& name);
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
void get_second(const string& second, const string& first);
void output(const string& filename);