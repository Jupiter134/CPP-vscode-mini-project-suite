#include <iostream>
using namespace std;

// 4.4 power function

int powerFunc(int base, int expo)
{
    // start with 1 rather than 0 for multiplying
    int result = 1;

    while(expo>0)
    {
        // if exponenent is odd, multply result by base once
        // makes exponent even so can /2 each iteration
        if(expo%2 == 1)
        {
            result = result*base;
            expo--;
        }

        // square the base and half the exponent
        // this is O(logn) time because ie. 2^4 = 2 x 2 x 2 x 2 = 16
        // standard way requires 3 calculations, (((2x2)x2)x2)
        // by squaring the base and halving the exponent, you only have to 
        // do a fraction of the calculations, because the new base and expo are retained
        // new: 2^4 = 
        //      1. (exponent = 2 > 0) 2x2=4, exponent 2/2 = 1
        //      2. (exponenet = 1 > 0) 4x4=16, exponenet = 1/2 = 0 (with int division)
        // only 2 calculations, rather than 3.

        base = base*base;
        expo = expo/2;
    }
    return result;
}

// main
int main()
{
    int base; int expo;

    // get base and exponent from user input
    cout << "Please enter the base: ";
    cin >> base;

    cout << "Please enter the exponent: ";
    cin >> expo;

    // call function
    int result = powerFunc(base, expo);

    // print result
    cout << base << " to the power of " << expo << " is " << result << endl;

    return 0;
}