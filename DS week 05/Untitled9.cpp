#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node* first = NULL;
    Node* last = NULL;

    int data;

    cout << "Enter data: ";
    cin >> data;

    // Reserve space for a new node
    Node* p = new Node;

    // Put data into the node
    p->data = data;

    // New node is the last node
    p->next = NULL;

    // Make connections
    if (last != NULL) {
        // List is not empty
        last->next = p;
    }
    else {
        // List is empty
        first = p;
    }

    // Update last pointer
    last = p;

    // Display the list
    cout << "Linked List: ";

    Node* temp = first;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}