
#include <iostream>          // Include input/output library
using namespace std;          // Use standard namespace

class Que                    // Class name
{
    struct Node               // Structure for each queue node
    {
        int data;             // Stores the queue element
        Node* next;           // Pointer to the next node
    };

    Node* front;              // Points to the first node
    Node* rear;                // Points to the last node

public:

    Que()                     // Default constructor
    {
        front = NULL;         // Initially, front points to nothing
        rear = NULL;          // Initially, rear points to nothing
    }

    bool is_empty()           // Check whether queue is empty
    {
        if (front == NULL)    // If front is NULL, no node exists
            return true;      // Queue is empty
        else
            return false;     // Queue contains elements
    }

    void display()             // Display all queue elements
    {
        if (is_empty())        // Check whether queue is empty
        {
            cout << "\nQueue is empty.";
        }
        else
        {
            Node* temp = front;    // Start traversal from front

            while (temp != NULL)   // Continue until the last node
            {
                cout << "\nValue is: " << temp->data;
                                      // Print current node's data

                temp = temp->next; // Move to the next node
            }
        }
    }

    void Enqueue(int x)        // Insert an element at the rear
    {
        Node* newNode = new Node; // Create a new node dynamically

        newNode->data = x;      // Store value in the new node
        newNode->next = NULL;   // New node will be the last node

        if (is_empty())         // Check if queue has no elements
        {
            front = rear = newNode;
                                  // Both point to the first node
        }
        else
        {
            rear->next = newNode; // Link old rear to new node
            rear = newNode;       // Update rear to the new node
        }
    }

    int Dequeue()               // Remove an element from the front
    {
        if (is_empty())         // Check whether queue is empty
        {
            cout << "\nQueue is already empty.";
            return -1;          // Return -1 if no element exists
        }
        else
        {
            Node* temp = front; // Save address of front node
            int x = temp->data; // Store value before deleting node

            front = front->next; // Move front to the next node

            if (front == NULL)  // If queue becomes empty
            {
                rear = NULL;    // Rear must also become NULL
            }

            delete temp;        // Free memory of removed node

            return x;           // Return the deleted element
        }
    }
};

int main()                     // Main function
{
    Que q1;                    // Create first empty queue
    Que q2;                    // Create second empty queue
    Que q3;                    // Create third empty queue

    q1.Enqueue(5);             // Insert 5 into q1
    q2.Enqueue(7);             // Insert 7 into q2
    q3.Enqueue(6);             // Insert 6 into q3

    int x = q2.Dequeue();      // Remove front element from q2

    cout << "\nDequeued element from q2 is: " << x;
                                  // Display removed element

    cout << "\n\nQueue q1:";
    q1.display();              // Display elements of q1

    cout << "\n\nQueue q2:";
    q2.display();              // Display elements of q2

    cout << "\n\nQueue q3:";
    q3.display();              // Display elements of q3

    return 0;                  // End program successfully
}

