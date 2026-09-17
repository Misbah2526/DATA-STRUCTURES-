#include <iostream>
using namespace std;

int main() {
    int x = 10;

    // ref is a reference to x.
    int& ref = x;

    // printing value using ref
    cout << ref << endl;
    
    // Changing the value and printing again
    ref = 22;
    cout << ref;

    return 0;
}