
#include <iostream>              // Library for input and output
using namespace std;              // Use standard namespace

class Deque                      // Class for Double-Ended Queue
{
    struct Node                   // Structure of a linked-list node
    {
        int data;                 // Stores the value
        Node* next;               // Points to the next node
        Node* prev;               // Points to the previous node
    };

    Node* front;                  // Points to the first node
    Node* rear;                   // Points to the last node

public:

    Deque()                       // Default constructor
    {
        front = NULL;             // Initially, front points to nothing
        rear = NULL;              // Initially, rear points to nothing
    }

    bool is_empty()               // Check whether deque is empty
    {
        if (front == NULL)        // If front is NULL
            return true;          // Deque is empty
        else
            return false;         // Deque contains elements
    }

    void insertFront(int x)       // Insert element at the front
    {
        Node* newNode = new Node; // Create a new node dynamically

        newNode->data = x;        // Store value in the new node
        newNode->prev = NULL;     // No node exists before the new node
        newNode->next = front;    // Link new node to current front

        if (is_empty())           // Check whether deque is empty
        {
            front = rear = newNode;
                                  // Both pointers point to new node
        }
        else
        {
            front->prev = newNode; // Link old front to new node
            front = newNode;       // Update front pointer
        }
    }

    void insertRear(int x)        // Insert element at the rear
    {
        Node* newNode = new Node; // Create a new node dynamically

        newNode->data = x;        // Store value in the new node
        newNode->next = NULL;     // No node exists after new node
        newNode->prev = rear;     // Link new node to current rear

        if (is_empty())           // Check whether deque is empty
        {
            front = rear = newNode;
                                  // Both point to the first node
        }
        else
        {
            rear->next = newNode; // Link old rear to new node
            rear = newNode;       // Update rear pointer
        }
    }

    int deleteFront()             // Delete element from the front
    {
        if (is_empty())           // Check if deque is empty
        {
            cout << "\nDeque is empty.";
            return -1;            // Return -1 if no element exists
        }

        Node* temp = front;       // Save address of front node
        int x = temp->data;       // Save value before deletion

        front = front->next;      // Move front to the next node

        if (front == NULL)        // If deque becomes empty
        {
            rear = NULL;          // Rear must also become NULL
        }
        else
        {
            front->prev = NULL;   // New front has no previous node
        }

        delete temp;              // Release memory of deleted node
        return x;                 // Return deleted element
    }

    int deleteRear()              // Delete element from the rear
    {
        if (is_empty())           // Check if deque is empty
        {
            cout << "\nDeque is empty.";
            return -1;            // Return -1 if no element exists
        }

        Node* temp = rear;        // Save address of rear node
        int x = temp->data;       // Save value before deletion

        rear = rear->prev;        // Move rear to previous node

        if (rear == NULL)         // If deque becomes empty
        {
            front = NULL;         // Front must also become NULL
        }
        else
        {
            rear->next = NULL;    // New rear has no next node
        }

        delete temp;              // Release memory of deleted node
        return x;                 // Return deleted element
    }

    void display()                // Display all deque elements
    {
        if (is_empty())           // Check whether deque is empty
        {
            cout << "\nDeque is empty.";
            return;               // Stop the function
        }

        Node* temp = front;       // Start from the front node

        cout << "\nDeque elements: ";

        while (temp != NULL)      // Continue until the last node
        {
            cout << temp->data << " "; // Print current node value
            temp = temp->next;         // Move to the next node
        }

        cout << endl;             // Move output to the next line
    }

    ~Deque()                      // Destructor
    {
        while (!is_empty())       // Continue while nodes exist
        {
            deleteFront();        // Delete each remaining node
        }
    }
};

int main()                        // Main function
{
    Deque d;                      // Create a deque object

    d.insertFront(10);            // Insert 10 at the front
    d.insertRear(20);             // Insert 20 at the rear
    d.insertFront(5);             // Insert 5 at the front
    d.insertRear(30);             // Insert 30 at the rear

    cout << "After insertion:";
    d.display();                  // Display all elements

    int x = d.deleteFront();      // Delete front element
    cout << "\nDeleted from front: " << x;

    int y = d.deleteRear();       // Delete rear element
    cout << "\nDeleted from rear: " << y;

    cout << "\nAfter deletion:";
    d.display();                  // Display remaining elements

    return 0;                     // End program successfully
}
