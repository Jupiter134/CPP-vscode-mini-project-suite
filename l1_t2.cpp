#include <iostream>
using namespace std;

// 4.2 greatest common divisor
int greatestComDiv(int num1, int num2)
{
    // repeatedly divide two numbers
    // use remainder to replace the bigger number until remainder is 0
    // (also then sorts issue if a is smaller than b, as
    // smallA % bigB = a)
    // until remainder is 0, then num1 is the GCD
    while(num2!=0)
    {
        int remainder = num1 % num2;
        num1 = num2;
        num2 = remainder;
    }
    return num1;  
}

// main
int main()
{
    int num1; int num2;

    // get first and second integers from user input
    cout << "Please enter the first integer: ";
    cin >> num1;

    cout << "Please enter the second integer: ";
    cin >> num2;

    // call function
    int result = greatestComDiv(num1, num2);

    // print result
    cout << "Greatest common divisor: " << result << endl;

    return 0;
}