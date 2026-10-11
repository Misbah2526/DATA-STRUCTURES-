#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Doubly linked list structure
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

    // Empty list
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

// Delete the first node
void deleteFirst(List* L) {

    // Check if list is empty
    if (L->first == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    Node* p = L->first;

    // Move first to the next node
    L->first = L->first->next;

    // If list became empty
    if (L->first == NULL) {
        L->last = NULL;
    }
    else {
        // New first node has no previous node
        L->first->prev = NULL;
    }

    // Release memory
    delete p;
}

// Delete the last node
void deleteLast(List* L) {

    // Check if list is empty
    if (L->last == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    Node* p = L->last;

    // Move last to previous node
    L->last = L->last->prev;

    // If list became empty
    if (L->last == NULL) {
        L->first = NULL;
    }
    else {
        // New last node has no next node
        L->last->next = NULL;
    }

    // Release memory
    delete p;
}

// Delete a node by its key
void deleteByKey(List* L, int key) {

    // Check if list is empty
    if (L->first == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    // Search for the node
    Node* p = L->first;

    while (p != NULL && p->data != key) {
        p = p->next;
    }

    // Key not found
    if (p == NULL) {
        cout << "Key " << key << " not found." << endl;
        return;
    }

    // Case 1: Only one node in the list
    if (L->first == p && L->last == p) {

        L->first = NULL;
        L->last = NULL;

        delete p;
    }

    // Case 2: Deleting the first node
    else if (p == L->first) {

        L->first = L->first->next;
        L->first->prev = NULL;

        delete p;
    }

    // Case 3: Deleting the last node
    else if (p == L->last) {

        L->last = L->last->prev;
        L->last->next = NULL;

        delete p;
    }

    // Case 4: Deleting an inner node
    else {

        p->next->prev = p->prev;
        p->prev->next = p->next;

        delete p;
    }
}

// Main function
int main() {

    List L;

    // Creating the list
    insertLast(&L, 10);
    insertLast(&L, 20);
    insertLast(&L, 30);
    insertLast(&L, 40);
    insertLast(&L, 50);

    cout << "Original list:" << endl;
    display(&L);

    // Delete first node
    cout << "\nAfter deleting first node:" << endl;
    deleteFirst(&L);
    display(&L);

    // Delete last node
    cout << "\nAfter deleting last node:" << endl;
    deleteLast(&L);
    display(&L);

    // Delete node by key
    cout << "\nDeleting node with key 30:" << endl;
    deleteByKey(&L, 30);
    display(&L);

    return 0;
}