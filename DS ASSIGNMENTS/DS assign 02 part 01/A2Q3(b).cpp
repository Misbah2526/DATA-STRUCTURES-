#include <iostream>                 // include iostream
using namespace std;                // allow std namespace

// ---------- Node ----------
struct Node {                       // node structure
    int data;                       // data stored
    Node* next;                     // next pointer
    Node(int d) : data(d), next(nullptr) {} // constructor
};

// ---------- Linked-List Queue ----------
class LinkedQueue {                 // queue implemented with linked list
public:                             // public members (simplify access in main)
    Node *front, *rear;             // front and rear pointers
    LinkedQueue() { front = rear = nullptr; } // constructor
    ~LinkedQueue() { while (!isEmpty()) dequeue(); } // destructor frees nodes

    bool isEmpty() { return front == nullptr; } // empty check

    void enqueue(int x) {                           // enqueue function
        Node* n = new Node(x);                      // create new node
        if (rear == nullptr) { front = rear = n; return; } // handle first element
        rear->next = n;                             // attach node after rear
        rear = n;                                   // update rear
    }

    int dequeue() {                                 // dequeue function
        if (isEmpty()) return -1;                   // return -1 if empty
        int val = front->data;                      // save front data
        Node* t = front;                            // save node to delete
        front = front->next;                        // move front
        if (front == nullptr) rear = nullptr;       // if empty reset rear
        delete t;                                   // delete node
        return val;                                 // return value
    }
};

// ---------- Bubble Sort using Linked Queue ----------
void bubbleSortUsingQueue(LinkedQueue &q, int n) {  // bubble sort function
    for (int i = 0; i < n - 1; i++) {               // n-1 passes
        int carry = q.dequeue();                    // start with first element
        bool swapped = false;                       // track swaps
        for (int j = 0; j < n - 1 - i; j++) {       // traverse remaining
            int curr = q.dequeue();                 // take next element
            if (carry > curr) {                     // out of order?
                q.enqueue(curr);                    // enqueue smaller
                swapped = true;                     // mark swap
            } else {                                // in order
                q.enqueue(carry);                   // enqueue carry
                carry = curr;                       // new carry is curr
            }
        }
        q.enqueue(carry);                           // enqueue largest at end
        if (!swapped) break;                        // early exit
    }
}

// ---------- Main ----------
int main() {                                // entry point
    int arr[] = {5, 1, 4, 2, 8};            // sample array
    int n = sizeof(arr) / sizeof(arr[0]);   // compute size

    LinkedQueue q;                          // create queue
    for (int i = 0; i < n; i++) q.enqueue(arr[i]); // load array

    bubbleSortUsingQueue(q, n);             // sort

    cout << "Sorted (linked-queue bubble sort): "; // print header
    while (!q.isEmpty()) cout << q.dequeue() << " "; // print each element
    cout << endl;                           // newline

    return 0;                               // exit
}