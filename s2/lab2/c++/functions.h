#include <iostream>
#include <cstring>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

struct Date;
struct Worker;
void get_date(Worker per);
string get_number();
void create_file(const string& name);
void input_data(Worker per);
string get_gender();
void output_file(const string& name);
bool is_number(const string& word);
string get_day();
string get_month();
string get_year();