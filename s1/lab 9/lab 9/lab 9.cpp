#include <cstringt.h>
#include <iostream>
#include <stdio.h>

using namespace std;
bool first_last(char*);
int find_same(char*);

int main()
{
    const int len = 50;
    char line[len];
    cout << "Enter a string: ";
    gets_s(line);
    
    int number;
    number = find_same(line);

    cout << "Number of words with the same first and last symbols: " << number;
}

bool first_last(char* str) {
    if (str[0] == str[strlen(str) - 1]) return true;
    else return false;
}

int find_same(char* string) {
    int n = 0;
    char seps[] = " ,.";
    char* next = NULL;
    char* left = strtok_s(string, seps, &next);
    while (left != NULL)
    {
        if (first_last(left)) {
            n += 1;
            printf("%s\n", left);
        }
        left = strtok_s(NULL, seps, &next);
    }

    return n;
}