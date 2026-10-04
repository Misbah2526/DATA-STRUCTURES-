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

// Delete all occurrences of a given ID
void deleteAllInstances(int bookID) {
    // Handle head deletions
    while (first != NULL && first->data == bookID) {
        NodeType *temp = first;
        first = first->next;
        delete temp;
    }
    if (first == NULL) { last = NULL; return; }
    
    // Handle middle and end
    NodeType *current = first;
    while (current != NULL && current->next != NULL) {
        if (current->next->data == bookID) {
            NodeType *temp = current->next;
            current->next = current->next->next;
            if (temp == last) last = current;
            delete temp;
        } else {
            current = current->next;
        }
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
    insert_end(5); insert_end(10); insert_end(5);
    insert_end(20); insert_end(5); insert_end(30);
    insert_end(5);
    
    cout << "Original: "; display();
    deleteAllInstances(5);
    cout << "After deleting 5: "; display();
    
    return 0;
}