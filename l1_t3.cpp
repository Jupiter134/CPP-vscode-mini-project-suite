#include <iostream>
using namespace std;

// 4.3 palindrome number
bool palindromeNumber(int number)
{
    // reuse reverseIntValue code from 4.1 to get the reverse of the number
    // compare reversed to original and return true or false
    int original = number;
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

    // if inputted number is the same as number with digits reversed,
    // then it's a palindrome, so return true
    if(original == reversed)
    {
        return true;
    }
    // otherwise it's not a palindrome, return false
    return false;
}

// main
int main()
{
    int number;

    // get integer to check from user input
    cout << "Please enter an integer: ";
    cin >> number;

    // call function
    bool result = palindromeNumber(number);

    // print yes or no depending on function return value
    if(result)
    {
        cout << "Integer is a palindrome." << endl;
    }
    else
    {
        cout << "Integer is not a palindrome." << endl;
    }

    return 0;
}