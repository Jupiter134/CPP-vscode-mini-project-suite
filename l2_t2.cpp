#include <iostream>
#include <cstddef>    // for NULL
using namespace std;

// reused length function from t1
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

/* copies src into dest, including its null char
/ returns NULL if dest < src, otherwise returns dest
/ arguments: 
/       dest - destination buffer holding null-terminated string
/       src - null-terminated source string
*/

char* copy (char* dest, const char* src)
{
    // if dest pointer is NULL or src is empty, return NULL 
    if(dest == NULL || src == NULL) return NULL;
    // get size of src
    unsigned int len = length(src);
    // return NULL if dest is too small for src
    // NOTE: I am using 10 here as dest is declared as size 11
    // in main (10 bytes plus null char)
    // i know this is sloppy but no max size is given for 
    if(len > 10) return NULL;

    // if all good, copy src into dest and return dest
    for(unsigned int i=0; i<= len; i++)
    {
        dest[i] = src[i];
    }
    return dest;
}


// TEST CASES

// tc1 -> check normal string
// expected result: 0
void copy_test_case_1()
{
    char dest[11];
    char src[100] = "my string";
    if(copy(dest, src) != NULL)
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
void copy_test_case_2()
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
void copy_test_case_3()
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
void copy_test_case_4()
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



int main ()
{
    // NOTE: there is no size given for dest so I used 11 bytes
    // max dest is 10 characters plus NULL char
    // max src is 99 characters plus NULL char
    char dest[11];
    char src[100];

    // get src from user input
    cout << "NOTE: destination can only support strings of length 10."
    << endl << "Please enter your string: " << endl;
    cin >> src;

    // call function and print result
    cout << "Result -- destination contains:  " << copy(dest, src) << endl;


    // run test cases
    copy_test_case_1();
    copy_test_case_2();
    copy_test_case_3();
    copy_test_case_4();

    return 0;
}