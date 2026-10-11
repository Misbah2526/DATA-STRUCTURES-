#include <iostream>
using namespace std;

// Node structure for Doubly Linked List
struct Node {
    int data;
    Node* next;
    Node* prev;
    
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// Function to reverse the Doubly Linked List
Node* reverseDLL(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head; // Empty list or single node
    }

    Node* current = head;
    Node* temp = nullptr;

    // Traverse the list and swap next and prev pointers
    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        
        // Move to the next node in the original list (which is now 'prev')
        current = current->prev; 
    }

    // Update the head pointer to the new front (old tail)
    if (temp != nullptr) {
        head = temp->prev; 
    }

    return head;
}

// Helper function to print the list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Helper function to insert a node at the end
void append(Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);
    Node* last = *head_ref;
    
    if (*head_ref == nullptr) {
        *head_ref = new_node;
        return;
    }
    while (last->next != nullptr) {
        last = last->next;
    }
    last->next = new_node;
    new_node->prev = last;
}

int main() {
    Node* head = nullptr;

    // Creating a sample Doubly Linked List: 10 <-> 20 <-> 30 <-> 40
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    append(&head, 40);

    cout << "Original Doubly Linked List: ";
    printList(head);

    // Reversing the list
    head = reverseDLL(head);

    cout << "Reversed Doubly Linked List: ";
    printList(head);

    return 0;
}