#include <iostream>
using namespace std;

// length function returns length of string exluding \0
// NO BUILT-IN CPP STRING FUNCTIONS

 
unsigned int length(const char* str)
{
    // arguments: str - a pointer to a null-terminated string

    // count stores number of characters
    unsigned int count = 0;

    // count will increase with every char found
    // terminates when null char is found (at end)
    // returns 0 if string is empty
    while(str[count] != '\0')
    {
        count++;
    }
    return count;
}

// TEST CASES

// tc1 -> check empty string
// expected result: 0
void length_test_case_1()
{
    if(length("") == 0)
    {
        cout << "test case 1: PASSED" << endl;
    }
    else
    {
        cout << "test case 1: FAILED" << endl;
    }
}

// tc2 -> check typical string
// expected result: 6
void length_test_case_2()
{
    if(length("string") == 6)
    {
        cout << "test case 2: PASSED" << endl;
    }
    else
    {
        cout << "test case 2: FAILED" << endl;
    }
}

// tc3 -> check string containing NULL char
// expected result: 6
void length_test_case_3()
{
    if(length("string\0") == 6)
    {
        cout << "test case 3: PASSED" << endl;
    }
    else
    {
        cout << "test case 3: FAILED" << endl;
    }
}

// tc4 -> checks string of single char
// expected result: 1
void length_test_case_4()
{
    if(length("p") == 1)
    {
        cout << "test case 4: PASSED" << endl;
    }
    else
    {
        cout << "test case 4: FAILED" << endl;
    }
}

// NOTE: if user enters "string\0" function will return 8
// I'm assuming this is just to check for null character
// that c++ adds automatically

// main
int main ()
{
    // char array for input
    // can handle up to 999 chars plus '\0'
    char str[1000];
    
    // get string for char array from user input
    cout << "Please enter your string: " << endl;
    cin >> str;

    // call function
    int result = length(str);

    // print result 
    cout << "The length of your string '" << str << "' is " << result << endl; 
    

    // run test cases
    length_test_case_1();
    length_test_case_2();
    length_test_case_3();
    length_test_case_4();

    return 0;
}

