#include <iostream>
#include <cstddef>
using namespace std;

// reusing length function from t1 again
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


// returns a substring of a string from i to j-1
// valid range: 0<= i <= j <= string length
// arguments:
//      i - index of first character to take
//      j - j-1 is index of last character to take
// returns a new string allocated with new [] 
// free with delete []
// returns NULL if range is invalid or string is NULL

char* substring(int i, int j, const char* str)
{
    // if string is empty there can't be a substring
    if(str == NULL) return NULL;

    // get length of string to check j doesn't exceed boundary
    int size = length(str);

    // return NULL is i is negative, j > length of string, 
    // i > j, or i == j (empty string)
    if(i < 0 || j > size || i > j || i == j) return NULL;

    // substring has j-i chars + 1 (for null char)
    char* result = new char[j - i + 1];

    // copy chars within substring range into result
    // tc2 was failing because the start of the array
    // was filling with garbage
    // if you only take middle of string, and copy to
    // middle of result while leaving result[0] etc empty,
    // the start will fill with garbage. seperate variable!
    int p = 0;
    for(int k=i; k<j; k++)
    {
        result[p] = str[k];
        p++;
    }
    
    // add null char '\0' at end so its a valid c-string
    result[p] = '\0';

    return result;
}


// TEST CASES

// boolean helper function to compare cstrings
bool equal(const char* one, const char* two)
{
    int i=0;
    //loop as long as theres no mismatch and not at end of either string
    while(one[i] != '\0' && two[i] != '\0')
    {
        // mismatch, not same, return false
        if(one[i] != two[i])
        {
            return false;
        }
        i++;
    }
    // if both end at same time, return true, otherwise false
    return(one[i] == '\0' && two[i] == '\0');
}

// tc1 -> check first 3 chars of string
// expected result: s, t, r
void substring_test_case_1()
{
    if(equal(substring(0, 3, "string"), "str"))
    {
        cout << "test case 1: PASSED" << endl;
    }
    else
    {
        cout << "test case 1: FAILED" << endl;
    }
}

// tc2 -> check middle characters
// expected result: rin
void substring_test_case_2()
{
    if(equal(substring(2, 5, "string"), "rin"))
    {
        cout << "test case 2: PASSED" << endl;
    }
    else
    {
        cout << "test case 2: FAILED" << endl;
    }
}

// tc3 -> check i=0, j=length (whole string)
// expected result: string
void substring_test_case_3()
{
    if(equal(substring(0, 6, "string"), "string"))
    {
        cout << "test case 3: PASSED" << endl;
    }
    else
    {
        cout << "test case 3: FAILED" << endl;
    }
}

// tc4 -> check j > length
// expected result: NULL (fails function, passes test)
void substring_test_case_4()
{
    if(substring(3,8, "string") == NULL)
    {
        cout << "test case 4: PASSED" << endl;
    }
    else
    {
        cout << "test case 4: FAILED" << endl;
    }
}

// tc5 -> check i out of range (i<0)
// expected result: NULL
void substring_test_case_5()
{
    if(substring(-1, 3, "string") == NULL)
    {
        cout << "test case 5: PASSED" << endl;
    }
    else
    {
        cout << "test case 5: FAILED" << endl;
    }
}

// tc6 -> check start is after end, i>j
// expected result: 4
void substring_test_case_6()
{
    if(substring(4, 2, "string") == NULL)
    {
        cout << "test case 6: PASSED" << endl;
    }
    else
    {
        cout << "test case 6: FAILED" << endl;
    }
}

// tc7 -> check i==j, so substring is an empty string
// expected result: NULL
void substring_test_case_7()
{
    if(substring(2, 2, "string") == NULL)
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
    int i = 0; int j = 0;
    
    // get string for char array from user input
    cout << "Please enter your string: " << endl;
    cin >> str;

    // get start index i from user input
    cout << "Please enter the index of your starting character (inclusive): " << endl;
    cin >> i;

    // get end index j from user input
    cout << "Please enter the index of your ending character (not inclusive): " << endl;
    cin >> j;

    // print result 
    cout << "Result: " << substring(i, j, str) << endl; 
    

    // run test cases
    substring_test_case_1();
    substring_test_case_2();
    substring_test_case_3();
    substring_test_case_4();
    substring_test_case_5();
    substring_test_case_6();
    substring_test_case_7();

    return 0;
}