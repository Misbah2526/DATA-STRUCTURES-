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

// Create loop for testing
void createLoop(int pos) {
    NodeType *loopNode = first;
    for (int i = 0; i < pos && loopNode != NULL; i++)
        loopNode = loopNode->next;
    if (loopNode != NULL) last->next = loopNode;
}

// Floyd's Cycle Detection (Tortoise & Hare)
bool detectLoop() {
    NodeType *slow = first;
    NodeType *fast = first;
    
    while (slow != NULL && fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

int main() {
    insert_end(1); insert_end(2); insert_end(3);
    insert_end(4); insert_end(5);
    
    createLoop(2);  // loop back to node index 2
    
    if (detectLoop())
        cout << "Loop detected!" << endl;
    else
        cout << "No loop found." << endl;
    
    return 0;
}