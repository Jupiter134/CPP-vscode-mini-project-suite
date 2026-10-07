#include <iostream>
using namespace std;
// 4.1 reverse an integer
int reverseIntValue(int number)
{
    int reversed = 0;
    int digit;

    while(number!=0)
    {
        //get last digit,
        // times reversed by 10 to 'move up' other numbers,
        // add last digit of number to reversed
        // divide number by 10 to get rid of used numbers
        digit = number%10;
        reversed = (reversed * 10) + digit;
        number = number / 10;
    }
    return reversed;
}

// main
// print string and result int, then move to next line
int main()
{
    int number;

    // get integer from user input
    cout << "Please enter an integer: ";
    cin >> number;

    // call function
    int result = reverseIntValue(number);

    // print result
    cout << "Reverse integer: " << result << endl;

    return 0;
}