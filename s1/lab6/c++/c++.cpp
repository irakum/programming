#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;
bool proste(int);
void twins(int);

int main()
{
    int n;
    cout << "Enter your number: ";
    cin >> n;
    while (n < 1){
        cout << "Wrong value. Enter a natural number: ";
        cin >> n;
    }

    for (int i = n; i < 2*n-1; i++)
    {
        twins(i);
    }
}

// перевірка, чи є число простим
bool proste(int number) {
    if (number <= 1) return false;
    
    int count = 0;
    for (int i = 1; i <= sqrt(number); i++) {
        if (number % i == 0) count++;
    }
    
    if (count == 1) return true;
    else return false;
}

// перевірка, чи є числа близнюками
void twins(int number) {
    if (proste(number) and proste(number + 2))
    {
        cout << number << " and " << number + 2 << endl;
    }
}