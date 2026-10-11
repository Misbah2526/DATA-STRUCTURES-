#include <iostream>

using namespace std;

// Definition of a node in a Doubly Linked List
struct Node {
    int data;
    Node* next;
    Node* prev;
    
    // Constructor for easy node creation
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
public:
    Node* head;

    DoublyLinkedList() : head(nullptr) {}

    // Function to insert a node at the end (for testing setup)
    void append(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    // Function to print the list forward (for testing)
    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // ==========================================
    // LAB TASK 2 SOLUTION
    // ==========================================
    void swapNodesByValue(int val1, int val2) {
        // 1. If the values are the same, no need to swap
        if (val1 == val2) {
            cout << "Values are identical. No swap needed." << endl;
            return;
        }

        // 2. Search for the two nodes
        Node* node1 = head;
        while (node1 != nullptr && node1->data != val1) {
            node1 = node1->next;
        }

        Node* node2 = head;
        while (node2 != nullptr && node2->data != val2) {
            node2 = node2->next;
        }

        // Check if both values were found in the list
        if (node1 == nullptr || node2 == nullptr) {
            cout << "One or both values not found in the list. Swap aborted." << endl;
            return;
        }

        // 3. Swapping the nodes (adjusting pointers)
        // Note: We do NOT swap the 'data' variable, we change the actual nodes.

        // A. Update the 'next' pointer of the node BEFORE node1
        if (node1->prev != nullptr) {
            node1->prev->next = node2;
        } else {
            // node1 was the head
            head = node2;
        }

        // B. Update the 'next' pointer of the node BEFORE node2
        if (node2->prev != nullptr) {
            node2->prev->next = node1;
        } else {
            // node2 was the head
            head = node1;
        }

        // C. Swap the 'prev' pointers of node1 and node2
        Node* tempPrev = node1->prev;
        node1->prev = node2->prev;
        node2->prev = tempPrev;

        // D. Swap the 'next' pointers of node1 and node2
        Node* tempNext = node1->next;
        node1->next = node2->next;
        node2->next = tempNext;

        // E. Fix the 'prev' pointers of the nodes that FOLLOW node1 and node2
        if (node1->next != nullptr) {
            node1->next->prev = node1;
        }
        if (node2->next != nullptr) {
            node2->next->prev = node2;
        }
    }
};

int main() {
    DoublyLinkedList dll;
    
    // Creating a sample list: 10 <-> 20 <-> 30 <-> 40 <-> 50
    dll.append(10);
    dll.append(20);
    dll.append(30);
    dll.append(40);
    dll.append(50);

    cout << "Original List: ";
    dll.printList();

    int val1, val2;
    cout << "Enter two values to swap (e.g., 20 40): ";
    cin >> val1 >> val2;

    // Call the Lab Task 2 function
    dll.swapNodesByValue(val1, val2);

    cout << "List after swapping " << val1 << " and " << val2 << ": ";
    dll.printList();

    return 0;
}