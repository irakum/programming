#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main()
{
    int max_fib = 100;
    
    int new_last, num_new, sec_last, last;
    new_last = 1;
    num_new = 1;
    sec_last = 1;
    last = 1;

    while ((last + sec_last) <= max_fib)
    {
        new_last = last + sec_last;
        num_new += 1;
        sec_last = last;
        last = new_last;

        int sum_i = 0;
        
        for (int i = 1; i <= sqrt(new_last); i++)
        {
            if (new_last % i == 0) sum_i += 1;
        }
        if (sum_i == 1) cout << new_last << " with a serial number " << num_new << endl;
    }
}
