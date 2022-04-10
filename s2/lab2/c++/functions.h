#include <iostream>
#include <cstring>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <cstdio>

using namespace std;

struct Date;
struct Worker;
string get_number();
void create_file(const string& name);
Worker input_data();
string get_gender();
void output_file(const string& name);
bool is_number(const string& word);
string get_day();
string get_month();
int get_year();
string get_name();
int get_amount();
void create_sorted(const string& old, const string& under, const string& over);
