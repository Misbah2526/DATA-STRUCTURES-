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

// Remove duplicates without extra data structure
void removeDuplicates() {
    NodeType *current = first;
    
    while (current != NULL && current->next != NULL) {
        NodeType *runner = current;
        
        while (runner->next != NULL) {
            if (runner->next->data == current->data) {
                NodeType *dup = runner->next;
                runner->next = runner->next->next;
                if (dup == last) last = runner;
                delete dup;
            } else {
                runner = runner->next;
            }
        }
        current = current->next;
    }
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
    insert_end(10); insert_end(20); insert_end(10);
    insert_end(30); insert_end(20); insert_end(40);
    insert_end(30);
    
    cout << "Original: "; display();
    removeDuplicates();
    cout << "After removing duplicates: "; display();
    
    return 0;
}