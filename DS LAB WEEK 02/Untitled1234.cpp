#include <iostream>
using namespace std;

int main() {
    int var = 10;
    cout << "Value of var: " << var << endl;
    // declare pointer and store address of var
    int* ptr = &var;
    *ptr =33;

    // print value and address

    cout << "Address of var: " << &var << endl;
    cout << "Value stored in pointer ptr: " << ptr << endl;
    cout << "Value pointed to by ptr: " << *ptr << endl;
    cout<< "value in var is now :"<<var<<endl;

    return 0;
}