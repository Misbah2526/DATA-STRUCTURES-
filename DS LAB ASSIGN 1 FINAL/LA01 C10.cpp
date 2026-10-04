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

// Swap every two consecutive nodes
void swapPairs() {
    if (first == NULL || first->next == NULL) return;
    
    // Dummy node simplifies edge cases
    NodeType *dummy = new NodeType;
    dummy->next = first;
    NodeType *prev = dummy;
    
    while (prev->next != NULL && prev->next->next != NULL) {
        NodeType *firstNode = prev->next;
        NodeType *secondNode = firstNode->next;
        
        // Swap
        firstNode->next = secondNode->next;
        secondNode->next = firstNode;
        prev->next = secondNode;
        
        prev = firstNode;
    }
    
    first = dummy->next;
    delete dummy;
    
    // Update last pointer
    last = first;
    while (last != NULL && last->next != NULL)
        last = last->next;
}

void display() {
    NodeType *p = first;
    while (p != NULL) {
        cout << p->data;
        if (p->next != NULL) cout << " -> ";
        p = p->next;
    }
    cout << " -> NULL" << endl;
}

int main() {
    insert_end(1); insert_end(2); insert_end(3);
    insert_end(4); insert_end(5); insert_end(6);
    
    cout << "Original: "; display();
    swapPairs();
    cout << "Swapped: "; display();
    
    return 0;
}