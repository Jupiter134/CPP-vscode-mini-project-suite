#include <iostream>
#include <cstddef>
using namespace std;

//reusing length function from t1 againnn
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



char* replace(char c, char p, const char* str)
{
    // return NULL if string is NULL - no string, 
    // nothing to replace
    if(str == NULL) return NULL;

    // new string is same length as old so use length
    // + 1 for NULL char
    unsigned int len = length(str);
    char* result = new char[len + 1];

    // go through orig string char by char
    // if you find a c, store p instead
    // otherwise store the orig char
    for(unsigned int i=0; i<len; i++)
    {
        if(str[i] == c)
        {
            result[i] = p;
        }
        else
        {
            result[i] = str[i];
        }
    }

    // add NULL char to end of new string and return
    result[len] = '\0';
    return result;
}

// TEST CASES

// reusing equal from t4
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

// tc1 -> check no c's so no changes
// expected result: string
void replace_test_case_1()
{
    if(equal(replace('x', 'g', "string"), "string"))
    {
        cout << "test case 1: PASSED" << endl;
    }
    else
    {
        cout << "test case 1: FAILED" << endl;
    }
}

// tc2 -> check one i becomes o
// expected result: strong
void replace_test_case_2()
{
    if(equal(replace('i', 'o', "string"), "strong"))
    {
        cout << "test case 2: PASSED" << endl;
    }
    else
    {
        cout << "test case 2: FAILED" << endl;
    }
}

// tc3 -> check two of same letter change, not just one
// expected result: hemmo
void replace_test_case_3()
{
    if(equal(replace('l', 'm', "hello"), "hemmo"))
    {
        cout << "test case 3: PASSED" << endl;
    }
    else
    {
        cout << "test case 3: FAILED" << endl;
    }
}

// tc4 -> check that empty string stays empty
// expected result: \0
void replace_test_case_4()
{
    if(equal(replace('a', 'q', ""), "\0"))
    {
        cout << "test case 4: PASSED" << endl;
    }
    else
    {
        cout << "test case 4: FAILED" << endl;
    }
}

// tc5 -> check every char matches so every char changes
// expected result: jjjjjjj
void replace_test_case_5()
{
    if(equal(replace('h','j', "hhhhhh"), "jjjjjj"))
    {
        cout << "test case 5: PASSED" << endl;
    }
    else
    {
        cout << "test case 5: FAILED" << endl;
    }
}

// tc6 -> check NULL string returns NULL
// expected result: NULL
void replace_test_case_6()
{
    if(replace('a', 'b', NULL) == NULL)
    {
        cout << "test case 6: PASSED" << endl;
    }
    else
    {
        cout << "test case 6: FAILED" << endl;
    }
}

// main
int main ()
{
    // char array for input
    // can handle up to 999 chars plus '\0'
    char str[1000];
    char c; char p;
    
    // get string for char array from user input
    cout << "Please enter your string: " << endl;
    cin >> str;

    // get start index i from user input
    cout << "Please enter the character you want to find and replace: " << endl;
    cin >> c;

    // get end index j from user input
    cout << "Please enter the character you want to replace it with: " << endl;
    cin >> p;

    // print result 
    cout << "Result: " << replace(c, p, str) << endl; 
    

    // run test cases
    replace_test_case_1();
    replace_test_case_2();
    replace_test_case_3();
    replace_test_case_4();
    replace_test_case_5();
    replace_test_case_6();
    

    return 0;
}