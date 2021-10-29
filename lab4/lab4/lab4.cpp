// lab4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <math.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    float i, n;
    cout << "Enter number of repetition: ";
    cin >> n;

    float x, y, sum;
    x = 1;                   // задання початкових значень х та у
    y = 1;
    sum = x / (1 + abs(y));

    //розрахування суми задану кількість разів
    for (i = 1; i <= n; i++)
    {
        y += x;
        x *= 0.3;
        sum += x / (1 + abs(y));
    }

    cout << "Final summary: " << sum;
}

