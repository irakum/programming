// lab3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <math.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    float precision;
    cout << "Enter precision: "; // введення точності
    cin >> precision;

    float y0, y;
    y0 = 0;                      // початкове значення у
    y = (y0 + 1) / (y0 + 2);

    // розрахування значення у з заданою точністю
    do
    {
        y0 = y;
        y = (y0 + 1) / (y0 + 2);
    } while (abs(y-y0) >= precision);

    cout << "Final value: " << y;  // виведення кінцевого значення у
}

