#include <iostream>
using namespace std;

// Node structure for Singly Linked List
struct SNode {
    int data;
    SNode* next;
    
    SNode(int val) : data(val), next(nullptr) {}
};

// Node structure for Doubly Linked List
struct DNode {
    int data;
    DNode* next;
    DNode* prev;
    
    DNode(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// Function to convert Singly Linked List to Doubly Linked List
DNode* convertSLLtoDLL(SNode* sllHead) {
    if (sllHead == nullptr) {
        return nullptr;
    }

    // Create the head of the new Doubly Linked List
    DNode* dllHead = new DNode(sllHead->data);
    DNode* dllCurrent = dllHead;
    
    SNode* sllCurrent = sllHead->next;

    // Traverse the Singly Linked List
    while (sllCurrent != nullptr) {
        // Create a new DLL node
        DNode* newNode = new DNode(sllCurrent->data);
        
        // Link the new node to the previous DLL node
        dllCurrent->next = newNode;
        newNode->prev = dllCurrent;
        
        // Move pointers forward
        dllCurrent = newNode;
        sllCurrent = sllCurrent->next;
    }

    return dllHead;
}

// Helper function to print Singly Linked List
void printSLL(SNode* head) {
    SNode* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Helper function to print Doubly Linked List
void printDLL(DNode* head) {
    DNode* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Helper function to insert a node at the end of SLL
void appendSLL(SNode** head_ref, int new_data) {
    SNode* new_node = new SNode(new_data);
    SNode* last = *head_ref;
    
    if (*head_ref == nullptr) {
        *head_ref = new_node;
        return;
    }
    while (last->next != nullptr) {
        last = last->next;
    }
    last->next = new_node;
}

int main() {
    SNode* sllHead = nullptr;

    // Creating a sample Singly Linked List: 1 -> 2 -> 3 -> 4 -> 5
    appendSLL(&sllHead, 1);
    appendSLL(&sllHead, 2);
    appendSLL(&sllHead, 3);
    appendSLL(&sllHead, 4);
    appendSLL(&sllHead, 5);

    cout << "Original Singly Linked List: ";
    printSLL(sllHead);

    // Converting to Doubly Linked List
    DNode* dllHead = convertSLLtoDLL(sllHead);

    cout << "Converted Doubly Linked List: ";
    printDLL(dllHead);

    return 0;
}