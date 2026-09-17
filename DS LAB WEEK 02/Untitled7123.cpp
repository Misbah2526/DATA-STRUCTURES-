#include <iostream>
using namespace std;
int x;
int* getPointer() {
     x = 120;
    
    // returning address of local variable
    return &x; 
}

int main() {
    
    // ptr becomes dangling here
    int* ptr;
	ptr= getPointer(); 
    cout<<ptr<<endl;
    // Undefined behavior
    int *ptr2=ptr;
    cout<<*ptr2<<endl;
     cout << *ptr<<endl;
     
     return 0;
    ;
}