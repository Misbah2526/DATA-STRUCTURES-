#include <iostream>                 // include iostream
using namespace std;                // allow std namespace

// ---------- Node ----------
struct Node {                       // node structure
    int data;                       // data
    Node* next;                     // next pointer
    Node(int d) : data(d), next(nullptr) {} // constructor
};

// ---------- Linked Queue ----------
class LinkedQueue {                 // queue implemented with linked list
public:                             // public members
    Node *front, *rear;             // front and rear pointers
    LinkedQueue() { front = rear = nullptr; } // constructor
    ~LinkedQueue() { while (!isEmpty()) dequeue(); } // destructor frees nodes

    bool isEmpty() { return front == nullptr; } // empty check

    void enqueue(int x) {                           // enqueue function
        Node* n = new Node(x);                      // create node
        if (rear == nullptr) { front = rear = n; return; } // first element
        rear->next = n;                             // attach after rear
        rear = n;                                   // update rear
    }

    int dequeue() {                                 // dequeue function
        if (isEmpty()) return -1;                   // empty case
        int v = front->data;                        // save value
        Node* t = front;                            // save node
        front = front->next;                        // move front
        if (front == nullptr) rear = nullptr;       // reset rear if empty
        delete t;                                   // delete node
        return v;                                   // return value
    }
};

// ---------- Selection Sort using Linked Queue ----------
void selectionSortUsingQueue(LinkedQueue &q, int n) {  // selection sort
    for (int i = 0; i < n - 1; i++) {                  // n-1 passes
        int minVal = q.dequeue();                      // start with first as min
        int cnt = n - 1 - i;                           // remaining element count
        int* buffer = new int[cnt];                    // buffer for others
        int size = 0;                                  // buffer size
        for (int j = 0; j < cnt; j++) {                // process each remaining
            int val = q.dequeue();                     // take next
            if (val < minVal) { buffer[size++] = minVal; minVal = val; } // new min
            else              { buffer[size++] = val; }                  // not new min
        }
        for (int j = 0; j < size; j++) q.enqueue(buffer[j]); // re-enqueue others
        q.enqueue(minVal);                             // enqueue min at end
        delete[] buffer;                               // free buffer
    }
}

// ---------- Main ----------
int main() {                                // entry point
    int arr[] = {11, 25, 12, 22, 64};       // sample array
    int n = sizeof(arr) / sizeof(arr[0]);   // compute size

    LinkedQueue q;                          // create queue
    for (int i = 0; i < n; i++) q.enqueue(arr[i]); // load elements

    selectionSortUsingQueue(q, n);          // sort

    cout << "Sorted (linked-queue selection sort): "; // header
    while (!q.isEmpty()) cout << q.dequeue() << " ";  // print each
    cout << endl;                           // newline

    return 0;                               // exit
}