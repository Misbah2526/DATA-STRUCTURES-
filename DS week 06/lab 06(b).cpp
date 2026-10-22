#include <iostream>
using namespace std;

// Define the structure for a Node in the doubly linked list
struct Node {
    int data;       // Variable to store data
    Node* prev;     // Pointer to the previous node
    Node* next;     // Pointer to the next node
};

// Class to implement the Deque using a doubly linked list
class Deque {
private:
    Node* front;    // Pointer to the front node
    Node* rear;     // Pointer to the rear node
    int size;       // Variable to keep track of the number of elements

public:
    // Constructor to initialize an empty deque
    Deque() {
        front = nullptr; // Initially front is null
        rear = nullptr;  // Initially rear is null
        size = 0;        // Initially size is zero
    }

    // Method to check if the deque is empty
    bool isEmpty() {
        return front == nullptr; // Returns true if front is null
    }

    // Method to add an element at the front
    void insertFront(int value) {
        Node* newNode = new Node; // Allocate memory for new node
        newNode->data = value;    // Assign value
        newNode->prev = nullptr;  // New front node's prev will be null
        newNode->next = front;    // New node's next points to current front

        if (isEmpty()) {          // If deque was empty
            front = newNode;      // New node is both front and rear
            rear = newNode;
        } else {
            front->prev = newNode; // Current front's prev points to new node
            front = newNode;       // Update front pointer to the new node
        }
        size++;                   // Increment size
        cout << value << " inserted at front.\n"; // Confirmation message
    }

    // Method to add an element at the rear
    void insertRear(int value) {
        Node* newNode = new Node; // Allocate memory for new node
        newNode->data = value;    // Assign value
        newNode->next = nullptr;  // New rear node's next will be null
        newNode->prev = rear;     // New node's prev points to current rear

        if (isEmpty()) {          // If deque was empty
            front = newNode;      // New node is both front and rear
            rear = newNode;
        } else {
            rear->next = newNode; // Current rear's next points to new node
            rear = newNode;       // Update rear pointer to the new node
        }
        size++;                   // Increment size
        cout << value << " inserted at rear.\n"; // Confirmation message
    }

    // Method to delete an element from the front
    void deleteFront() {
        if (isEmpty()) {          // Check if there is anything to delete
            cout << "Deque is empty. Cannot delete from front.\n";
            return;               // Exit function
        }
        
        Node* temp = front;       // Store current front to delete later
        front = front->next;      // Move front pointer to the next node

        if (front == nullptr) {   // If the deque becomes empty after deletion
            rear = nullptr;       // Set rear to null as well
        } else {
            front->prev = nullptr; // The new front's prev pointer becomes null
        }
        
        delete temp;              // Free the memory of the deleted node
        size--;                   // Decrement size
        cout << "Deleted from front.\n"; // Confirmation message
    }

    // Method to delete an element from the rear
    void deleteRear() {
        if (isEmpty()) {          // Check if there is anything to delete
            cout << "Deque is empty. Cannot delete from rear.\n";
            return;               // Exit function
        }
        
        Node* temp = rear;        // Store current rear to delete later
        rear = rear->prev;        // Move rear pointer to the previous node

        if (rear == nullptr) {    // If the deque becomes empty after deletion
            front = nullptr;      // Set front to null as well
        } else {
            rear->next = nullptr; // The new rear's next pointer becomes null
        }
        
        delete temp;              // Free the memory of the deleted node
        size--;                   // Decrement size
        cout << "Deleted from rear.\n"; // Confirmation message
    }

    // Method to get the front element
    int getFront() {
        if (isEmpty()) {          // Check if deque is empty
            cout << "Deque is empty.\n";
            return -1;            // Return error value
        }
        return front->data;       // Return data at front node
    }

    // Method to get the rear element
    int getRear() {
        if (isEmpty()) {          // Check if deque is empty
            cout << "Deque is empty.\n";
            return -1;            // Return error value
        }
        return rear->data;        // Return data at rear node
    }

    // Method to display the deque from front to rear
    void display() {
        if (isEmpty()) {          // Check if empty
            cout << "Deque is empty.\n";
            return;               // Exit function
        }
        
        Node* current = front;    // Start from the front node
        cout << "Deque elements: "; 
        while (current != nullptr) { // Loop until end
            cout << current->data << " "; // Print current data
            current = current->next;  // Move to next node
        }
        cout << "\nSize: " << size << endl; // Print size at the end
    }

    // Destructor to free memory
    ~Deque() {
        while (front != nullptr) { // Loop through all nodes
            Node* temp = front;    // Store current front
            front = front->next;   // Move front to next
            delete temp;           // Delete stored node
        }
    }
};

// Main function to test the Deque
int main() {
    Deque dq;                     // Create object of Deque
    dq.insertRear(10);            // Test insert at rear
    dq.insertRear(20);            // Test insert at rear
    dq.insertFront(5);            // Test insert at front
    dq.insertFront(1);            // Test insert at front
    dq.display();                 // Display elements (Expected: 1 5 10 20)

    cout << "Front element: " << dq.getFront() << endl; // Test get front
    cout << "Rear element: " << dq.getRear() << endl;   // Test get rear

    dq.deleteFront();             // Test delete from front
    dq.deleteRear();              // Test delete from rear
    dq.display();                 // Display elements (Expected: 5 10)

    return 0;                     // End of program
}