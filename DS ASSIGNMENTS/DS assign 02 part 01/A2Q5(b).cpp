#include <iostream>                 // include iostream
using namespace std;                // allow std namespace

// ---------- Node ----------
struct Node {                       // node structure
    int data;                       // data
    Node* next;                     // next pointer
    Node(int d) : data(d), next(nullptr) {} // constructor
};

// ---------- Linked Stack ----------
class LinkedStack {                 // stack via linked list
public:                             // public members
    Node* top;                      // pointer to top
    LinkedStack() { top = nullptr; } // constructor
    ~LinkedStack() { while (!isEmpty()) pop(); } // destructor frees nodes

    bool isEmpty() { return top == nullptr; } // empty check

    void push(int x) {                          // push function
        Node* n = new Node(x);                  // create node
        n->next = top;                          // point to old top
        top = n;                                // update top
    }

    int pop() {                                 // pop function
        if (isEmpty()) return -1;               // empty case
        int v = top->data;                      // save top data
        Node* t = top;                          // save node to delete
        top = top->next;                        // move top
        delete t;                               // delete node
        return v;                               // return data
    }

    int peek() { return isEmpty() ? -1 : top->data; } // peek top data
};

// ---------- Insertion Sort using Linked Stacks ----------
void insertionSortUsingStacks(LinkedStack &s1, LinkedStack &s2) { // insertion sort
    while (!s1.isEmpty()) {                            // process each input
        int curr = s1.pop();                           // take next element
        while (!s2.isEmpty() && s2.peek() > curr) {    // find position in s2
            s1.push(s2.pop());                         // move larger elements back to s1
        }
        s2.push(curr);                                 // insert curr into s2
    }
    while (!s2.isEmpty()) s1.push(s2.pop());           // move sorted to s1 (top = largest)
}

// ---------- Main ----------
int main() {                                    // entry point
    int arr[] = {9, 3, 7, 1, 5};                // sample array
    int n = sizeof(arr) / sizeof(arr[0]);       // compute size

    LinkedStack s1, s2;                         // two stacks
    for (int i = 0; i < n; i++) s1.push(arr[i]); // load input into s1

    insertionSortUsingStacks(s1, s2);           // sort

    cout << "Sorted (linked-stack insertion sort): "; // header
    LinkedStack temp;                           // temp for reversing
    while (!s1.isEmpty()) temp.push(s1.pop());  // reverse: temp top = smallest
    while (!temp.isEmpty()) cout << temp.pop() << " "; // print ascending
    cout << endl;                               // newline

    return 0;                                   // exit
}