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

// Reverse a segment from start to end
NodeType* reverseSegment(NodeType *start, NodeType *end) {
    NodeType *prev = NULL;
    NodeType *curr = start;
    NodeType *stop = end->next;
    
    while (curr != stop) {
        NodeType *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

// Reverse halves separately
void reverseHalves() {
    if (first == NULL || first->next == NULL) return;
    
    // Find middle
    NodeType *slow = first, *fast = first;
    NodeType *prevSlow = NULL;
    
    while (fast != NULL && fast->next != NULL) {
        prevSlow = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    NodeType *firstHalfStart = first;
    NodeType *firstHalfEnd = prevSlow;
    NodeType *secondHalfStart = slow;
    
    NodeType *secondHalfEnd = secondHalfStart;
    while (secondHalfEnd->next != NULL)
        secondHalfEnd = secondHalfEnd->next;
    
    // Reverse each half
    NodeType *newFirstHead = reverseSegment(firstHalfStart, firstHalfEnd);
    NodeType *newSecondHead = reverseSegment(secondHalfStart, secondHalfEnd);
    
    // Connect
    firstHalfStart->next = newSecondHead;
    first = newFirstHead;
}

void display() {
    NodeType *p = first;
    while (p != NULL) {
        cout << p->data;
        if (p->next != NULL) cout << " -> ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    for (int i = 1; i <= 8; i++) insert_end(i);
    
    cout << "Original: "; display();
    reverseHalves();
    cout << "After: "; display();
    
    return 0;
}