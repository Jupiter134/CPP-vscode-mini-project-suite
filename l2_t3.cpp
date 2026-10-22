#include <iostream>
#include <cstddef>   // for NULL
using namespace std;

// function takes a char and char array and searches
// the char array for the given char
// returns the index of the first instance of the char 
// if found
// returns -1 if not found.
// arguments:
//      c - character to look for
//      str - null-terminated string to search

int indexOf(char c, const char* str)
{
    // if pointer is NULL, return -1 for not found
    if(str == NULL) return -1;

    // search through the array looking for a match
    // return index if char is found
    // if reaches NULL char, then target char doesn't 
    // exist in string, so return -1 for not found
    for(int i=0; str[i] != '\0'; i++)
    {
        // return first match as soon as its found
        if(str[i] == c) return i;
    }
    return -1;
}

// TEST CASES

// tc1 -> check NULL string
// expected result: -1
void indexOf_test_case_1()
{
    if(indexOf('i', NULL) == -1)
    {
        cout << "test case 1: PASSED" << endl;
    }
    else
    {
        cout << "test case 1: FAILED" << endl;
    }
}

// tc2 -> check when match exists
// expected result: 3
void indexOf_test_case_2()
{
    if(indexOf('i', "string") == 3)
    {
        cout << "test case 2: PASSED" << endl;
    }
    else
    {
        cout << "test case 2: FAILED" << endl;
    }
}

// tc3 -> check when match doesn't exist
// expected result: -1
void indexOf_test_case_3()
{
    if(indexOf('a', "string") == -1)
    {
        cout << "test case 3: PASSED" << endl;
    }
    else
    {
        cout << "test case 3: FAILED" << endl;
    }
}

// tc4 -> check function returns FIRST instance of character
// when there are multiple of the same
// expected result: 2
void indexOf_test_case_4()
{
    if(indexOf('l', "hello") == 2)
    {
        cout << "test case 4: PASSED" << endl;
    }
    else
    {
        cout << "test case 4: FAILED" << endl;
    }
}

// tc5 -> check empty string
// expected result: -1
void indexOf_test_case_5()
{
    if(indexOf('l', "") == -1)
    {
        cout << "test case 5: PASSED" << endl;
    }
    else
    {
        cout << "test case 5: FAILED" << endl;
    }
}

// tc6 -> check when index is very first char
// expected result: 0
void indexOf_test_case_6()
{
    if(indexOf('h', "hello") == 0)
    {
        cout << "test case 6: PASSED" << endl;
    }
    else
    {
        cout << "test case 6: FAILED" << endl;
    }
}

// tc7 -> check when index is very last char (before null)
// expected result: 4
void indexOf_test_case_7()
{
    if(indexOf('o', "hello") == 4)
    {
        cout << "test case 7: PASSED" << endl;
    }
    else
    {
        cout << "test case 7: FAILED" << endl;
    }
}

// main
int main ()
{
    // char array for input
    // can handle up to 999 chars plus '\0'
    char str[1000];
    char c;
    
    // get string for char array from user input
    cout << "Please enter your string: " << endl;
    cin >> str;

    cout << "Please enter the character you're looking for: "
    << endl;
    cin >> c;


    // call function
    int result = indexOf(c, str);

    // print table of results
    cout << "NOTE: A result of -1 means the character was not found," <<
    " or the given string was empty or null. Any other result is the index of " <<
    "the given character in the given string." << endl;

    // print result 
    cout << "Result: " << result << endl; 
    

    // run test cases
    indexOf_test_case_1();
    indexOf_test_case_2();
    indexOf_test_case_3();
    indexOf_test_case_4();
    indexOf_test_case_5();
    indexOf_test_case_6();
    indexOf_test_case_7();

    return 0;
}

