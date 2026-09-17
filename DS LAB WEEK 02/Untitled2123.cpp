#include <iostream>
using namespace std;

int main() {
    int var = 10;
    
    // Store the address of 
    // var variable
    int* ptr = &var;
    
    // Access value using (*)
    // operator
    cout << *ptr;
    return 0;
}