#include <iostream>
using namespace std;

int main() {
    int var = 10;
    
    // Store the address of 
    // var variable
    int* ptr1 = &var;
    int** ptr2 = &ptr1;
    
    // Access values using (*)
    // operator
    cout << &ptr1 << endl;
    cout <<ptr2;
    return 0;
}