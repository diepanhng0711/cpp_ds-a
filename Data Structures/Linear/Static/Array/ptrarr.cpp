#include<iostream>

using namespace std;

int main() {
    //Pointer to an integer
    int *p;

    //Pointer to an array of 5 integers
    int (*ptr)[5];
    int arr[5];

    p = arr;
    ptr = &arr;

    cout << "p = " << p << ", ptr = " << ptr << endl ;
    p++;
    ptr++;
    cout << "p = " << p << ", ptr = " << ptr << endl ;

    return 0;
}