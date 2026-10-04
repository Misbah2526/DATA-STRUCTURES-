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

// Separate into even and odd lists
void separateEvenOdd(NodeType *&evenHead, NodeType *&oddHead) {
    evenHead = oddHead = NULL;
    NodeType *evenTail = NULL, *oddTail = NULL;
    
    NodeType *p = first;
    while (p != NULL) {
        NodeType *nextNode = p->next;
        p->next = NULL;  // detach
        
        if (p->data % 2 == 0) {
            if (evenHead == NULL) evenHead = evenTail = p;
            else { evenTail->next = p; evenTail = p; }
        } else {
            if (oddHead == NULL) oddHead = oddTail = p;
            else { oddTail->next = p; oddTail = p; }
        }
        p = nextNode;
    }
}

void displayList(NodeType *head, string name) {
    cout << name << ": ";
    NodeType *p = head;
    while (p != NULL) {
        cout << p->data << " -> ";
        p = p->next;
    }
    cout << "NULL" << endl;
}

int main() {
    insert_end(11); insert_end(20); insert_end(33);
    insert_end(40); insert_end(55); insert_end(60);
    
    NodeType *evenHead, *oddHead;
    separateEvenOdd(evenHead, oddHead);
    
    displayList(evenHead, "Even prices");
    displayList(oddHead, "Odd prices");
    
    return 0;
}