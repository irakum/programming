#include <iostream>
#include <math.h>
#include <stdio.h>

int main()
{
    float first, second, third;
    std::cout << "first number: "; std::cin >> first; //entering first number
    std::cout << "second number: "; std::cin >> second; //entering second number
    std::cout << "third number: "; std::cin >> third; //entering third number

    float geom_mean;
    geom_mean = pow(first * second * third, 1. / 3); //calculating geometric mean

    float fract_part, int_part;
    fract_part = modf(geom_mean, &int_part); //separating fractional part

    printf("The fractional part of the geometric mean: %f", fract_part);
}
