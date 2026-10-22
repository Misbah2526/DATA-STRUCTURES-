#include <iostream>                 // include iostream
using namespace std;                // allow std namespace

#define MAX 100                     // maximum queue capacity

// ---------- Array-based Circular Queue ----------
class ArrayQueue {                  // circular queue using array
private:                            // private members
    int arr[MAX];                   // underlying storage
    int front, rear, count;         // front index, rear index, current count
public:                             // public members
    ArrayQueue() { front = 0; rear = -1; count = 0; } // constructor

    bool isEmpty() { return count == 0; }   // empty if count 0
    bool isFull()  { return count == MAX; } // full if count MAX

    void enqueue(int x) {           // enqueue function
        if (isFull()) return;       // ignore if full
        rear = (rear + 1) % MAX;    // advance rear circularly
        arr[rear] = x;              // store value
        count++;                    // increment count
    }

    int dequeue() {                 // dequeue function
        if (isEmpty()) return -1;   // return -1 if empty
        int val = arr[front];       // save front value
        front = (front + 1) % MAX;  // advance front circularly
        count--;                    // decrement count
        return val;                 // return saved value
    }

    int getFront() { return isEmpty() ? -1 : arr[front]; } // return front
    int size()     { return count; }                        // return size
};

// ---------- Bubble Sort using Queue ----------
// Approach: each pass moves the largest remaining element to the end.
// We use one queue plus a "carry" variable holding the currently floating element.
void bubbleSortUsingQueue(ArrayQueue &q, int n) {              // bubble sort function
    for (int i = 0; i < n - 1; i++) {                          // perform n-1 passes
        int carry = q.dequeue();                               // start with first element as carry
        bool swapped = false;                                  // track if any swap occurred

        for (int j = 0; j < n - 1 - i; j++) {                  // compare remaining pairs
            int curr = q.dequeue();                            // take next element
            if (carry > curr) {                                // if out of order
                q.enqueue(curr);                               // enqueue smaller first
                swapped = true;                                // mark swapped
                // carry remains the larger element (it will continue bubbling)
            } else {                                           // if in order
                q.enqueue(carry);                              // enqueue carry first
                carry = curr;                                  // new carry is curr
            }
        }
        q.enqueue(carry);                                      // enqueue the pass's largest at end
        if (!swapped) break;                                   // early exit if sorted
    }
}

// ---------- Main ----------
int main() {                                // entry point
    int arr[] = {64, 34, 25, 12, 22, 11, 90}; // sample unsorted array
    int n = sizeof(arr) / sizeof(arr[0]);   // compute size

    ArrayQueue q;                           // create queue
    for (int i = 0; i < n; i++) q.enqueue(arr[i]); // load array into queue

    bubbleSortUsingQueue(q, n);             // sort using queue

    cout << "Sorted (array-queue bubble sort): "; // print header
    while (!q.isEmpty()) cout << q.dequeue() << " "; // dequeue each element
    cout << endl;                           // newline

    return 0;                               // exit
}