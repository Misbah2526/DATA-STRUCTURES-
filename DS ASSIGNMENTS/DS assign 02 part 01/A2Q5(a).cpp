#include <iostream>                 // include iostream
using namespace std;                // allow std namespace

#define MAX 100                     // maximum stack capacity

// ---------- Array-based Stack ----------
class ArrayStack {                  // stack using array
private:                            // private members
    int arr[MAX];                   // storage
    int top;                        // index of top
public:                             // public members
    ArrayStack() { top = -1; }      // constructor: empty stack
    bool isEmpty() { return top == -1; }    // empty check
    bool isFull()  { return top == MAX - 1; } // full check

    void push(int x) {              // push function
        if (isFull()) return;       // ignore if full
        arr[++top] = x;             // increment top then store
    }

    int pop() {                     // pop function
        if (isEmpty()) return -1;   // empty case
        return arr[top--];          // return top then decrement
    }

    int peek() { return isEmpty() ? -1 : arr[top]; } // peek top
};

// ---------- Insertion Sort using Stacks ----------
// Idea: s1 holds the input; s2 holds sorted elements (top = largest).
// For each element from s1, pop from s2 all elements larger than it into s1,
// then push it into s2, then move those larger elements back to s2.
// At end, move s2 back to s1 (s1 has sorted order, top = largest).
void insertionSortUsingStacks(ArrayStack &s1, ArrayStack &s2) { // insertion sort
    if (s1.isEmpty()) return;                          // nothing to sort

    while (!s1.isEmpty()) {                            // process every element
        int curr = s1.pop();                           // take next element
        while (!s2.isEmpty() && s2.peek() > curr) {    // find correct position in s2
            s1.push(s2.pop());                         // temporarily move larger elements back
        }
        s2.push(curr);                                 // insert curr into s2
    }
    while (!s2.isEmpty()) s1.push(s2.pop());           // move sorted result to s1 (top = largest)
}

// ---------- Main ----------
int main() {                                    // entry point
    int arr[] = {12, 11, 13, 5, 6};             // sample array
    int n = sizeof(arr) / sizeof(arr[0]);       // compute size

    ArrayStack s1, s2;                          // two stacks
    for (int i = 0; i < n; i++) s1.push(arr[i]); // load input into s1

    insertionSortUsingStacks(s1, s2);           // sort

    cout << "Sorted (array-stack insertion sort): "; // header
    ArrayStack temp;                            // temp stack to reverse order
    while (!s1.isEmpty()) temp.push(s1.pop());  // s1 top=largest -> temp top=smallest
    while (!temp.isEmpty()) cout << temp.pop() << " "; // print ascending
    cout << endl;                               // newline

    return 0;                                   // exit
}