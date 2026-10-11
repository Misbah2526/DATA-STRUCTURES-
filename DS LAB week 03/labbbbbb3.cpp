#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Doubly Linked List structure
struct List {
    Node* first;
    Node* last;

    // Constructor
    List() {
        first = NULL;
        last = NULL;
    }
};

// Create a new node
Node* createNode(int value) {
    Node* p = new Node;

    p->data = value;
    p->next = NULL;
    p->prev = NULL;

    return p;
}

// Insert a node at the end
void insertLast(List* L, int value) {
    Node* p = createNode(value);

    // If list is empty
    if (L->first == NULL) {
        L->first = L->last = p;
    }
    else {
        p->prev = L->last;
        L->last->next = p;
        L->last = p;
    }
}

// Display the list
void display(List* L) {
    Node* p = L->first;

    cout << "List: ";

    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }

    cout << endl;
}

// Delete the complete list
void deleteList(List* L) {

    Node* p;

    // Delete nodes one by one
    while (L->first != NULL) {

        // Store the first node
        p = L->first;

        // Move first to the next node
        L->first = L->first->next;

        // Free the old first node
        delete p;
    }

    // List is now empty
    L->last = NULL;
}

// Main function
int main() {

    List L;

    // Create a list
    insertLast(&L, 10);
    insertLast(&L, 20);
    insertLast(&L, 30);
    insertLast(&L, 40);
    insertLast(&L, 50);

    // Display original list
    cout << "Original list:" << endl;
    display(&L);

    // Delete the complete list
    deleteList(&L);

    // Display after deletion
    cout << "\nAfter deleting the complete list:" << endl;

    if (L.first == NULL) {
        cout << "List is empty." << endl;
    }
    else {
        display(&L);
    }

    return 0;
}