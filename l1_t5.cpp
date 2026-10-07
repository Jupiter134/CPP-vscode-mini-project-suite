#include <iostream>
using namespace std;

// 4.5 power of two

bool powerOfTwo(int k)
{
    // powers of 2 are 1, 2, 4, 8, etc.
    // k(k>0)
    int number = 1;

    // repeatedly multiply by 2
    // until number >= k
    while(number<k)
    {
        number = number*2;
    }

    // loop will stop when number>=k
    // if number==k, then its a power of 2
    // otherwise number>k, so k is not a power of
    if(number == k)
    {
        return true;
    }
    return false;
}

// main
int main()
{
    int k;

    // get k from user input
    cout << "Please enter k: ";
    cin >> k;

    // call function
    int result = powerOfTwo(k);

    // print result based on function return value 
    if(result)
    {
        cout << k << " is a power of 2." << endl;
    }
    else
    {
        cout << k << " is not a power of 2." << endl;
    }

    return 0;
}