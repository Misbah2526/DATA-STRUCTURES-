#include <iostream>
using namespace std;

// Node structure as per lab manual
struct NodeType {
    int data;
    NodeType *next;
};

NodeType *first = NULL, *last = NULL;

// Insert at end 
void insert_end(int value) {
    NodeType *p = new NodeType;
    p->data = value;
    p->next = NULL;
    
    if (first == NULL) {
        first = last = p;
    } else {
        last->next = p;
        last = p;
    }
}

// Recursive display in reverse 
void displayReverseRecursive(NodeType *p) {
    if (p == NULL) return;
    displayReverseRecursive(p->next);   // go to end first
    cout << p->data << " ";             // print on way back
}

// Iterative reverse display using recursion internally
void displayReverse() {
    cout << "List in reverse: ";
    displayReverseRecursive(first);
    cout << endl;
}

int main() {
    insert_end(100);  // oldest
    insert_end(200);
    insert_end(300);
    insert_end(400);  // newest
    
    displayReverse();  // 400 300 200 100
    
    return 0;
}