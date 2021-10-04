// lab2_c.cpp : 
//is it possible to fit the first rectangle in the second one

#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

int main()
{
    float a, b, c, d;
    cout << "Enter the first side of the first rectangle: ";
    cin >> a;
    if (a <= 0) {
        cout << "Invalid value, try again";
        exit(0);
    }
    cout << "Enter the second side of the first rectangle: ";
    cin >> b;
    if (b <= 0) {
        cout << "Invalid value, try again";
        exit(0);
    }
    cout << "Enter the first side of the second rectangle: ";
    cin >> c;
    if (c <= 0) {
        cout << "Invalid value, try again";
        exit(0);
    }
    cout << "Enter the second side of the second rectangle: ";
    cin >> d;
    if (d <= 0) {
        cout << "Invalid value, try again";
        exit(0);
    }

    float max_first, max_second;
    max_first = max(a, b); //greater side of the first rectangle
    max_second = max(c, d); //greater side of the second rectangle
    float min_first, min_second;
    min_first = min(a, b); //smaller side of the first rectangle
    min_second = min(c, d); //smaller side of the second rectangle

    if (max_second > max_first && min_second > min_first)
        cout << "It is possible to fit the first rectangle in the second one.";
    else cout << "It is possible to fit the first rectangle in the second one.";
}

