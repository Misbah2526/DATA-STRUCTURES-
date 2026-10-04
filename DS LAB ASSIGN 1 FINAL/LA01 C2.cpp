#include <iostream>
using namespace std;

struct NodeType {
    int data;
    NodeType *next;
};

NodeType *first = NULL, *last = NULL;

void insert_end(int value) {
    NodeType *p = new NodeType;
    p->data = value;
    p->next = NULL;
    if (first == NULL) first = last = p;
    else { last->next = p; last = p; }
}

// Reverse list by changing links only (addresses remain same)
void reverseList() {
    NodeType *prev = NULL;
    NodeType *current = first;
    NodeType *nextNode = NULL;
    
    last = first;  // old first becomes new last
    
    while (current != NULL) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    first = prev;
}

void display() {
    NodeType *p = first;
    while (p != NULL) {
        cout << p->data << " -> ";
        p = p->next;
    }
    cout << "NULL" << endl;
}

int main() {
    insert_end(1); insert_end(2); insert_end(3);
    insert_end(4); insert_end(5);
    
    cout << "Original: "; display();
    reverseList();
    cout << "Reversed: "; display();
    
    return 0;
}