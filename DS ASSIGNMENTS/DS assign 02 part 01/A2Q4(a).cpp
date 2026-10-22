#include <iostream>                 // include iostream
using namespace std;                // allow std namespace

#define MAX 100                     // maximum capacity

// ---------- Array-based Circular Queue ----------
class ArrayQueue {                  // circular queue using array
private:                            // private members
    int arr[MAX];                   // storage
    int front, rear, count;         // indices and count
public:                             // public members
    ArrayQueue() { front = 0; rear = -1; count = 0; } // constructor

    bool isEmpty() { return count == 0; } // empty check

    void enqueue(int x) {                   // enqueue function
        if (count == MAX) return;           // ignore if full
        rear = (rear + 1) % MAX;            // advance rear circularly
        arr[rear] = x;                      // store value
        count++;                            // increment count
    }

    int dequeue() {                         // dequeue function
        if (isEmpty()) return -1;           // return -1 if empty
        int v = arr[front];                 // save front
        front = (front + 1) % MAX;          // advance front circularly
        count--;                            // decrement count
        return v;                           // return value
    }

    int size() { return count; }            // return size
};

// ---------- Selection Sort using Queue ----------
// Idea: for each pass, find the minimum among the unsorted part,
// move all others to the back in original order, and enqueue the
// minimum at the end (its final sorted position at the back).
void selectionSortUsingQueue(ArrayQueue &q, int n) {  // selection sort function
    for (int i = 0; i < n - 1; i++) {                  // perform n-1 passes
        int minVal = q.dequeue();                      // start with first element as min
        int cnt = n - 1 - i;                           // number of remaining elements

        int* buffer = new int[cnt];                    // temporary buffer for others
        int size = 0;                                  // buffer size counter
        for (int j = 0; j < cnt; j++) {                // process each remaining element
            int val = q.dequeue();                     // take next element
            if (val < minVal) {                        // found new min?
                buffer[size++] = minVal;               // store old min to buffer
                minVal = val;                          // update new min
            } else {                                   // not new min
                buffer[size++] = val;                  // store to buffer
            }
        }
        for (int j = 0; j < size; j++) q.enqueue(buffer[j]); // re-enqueue unsorted
        q.enqueue(minVal);                             // enqueue min at the end (sorted position)
        delete[] buffer;                               // free buffer
    }
    // remaining one element is already in queue in correct position
}

// ---------- Main ----------
int main() {                                // entry point
    int arr[] = {29, 10, 14, 37, 13};       // sample array
    int n = sizeof(arr) / sizeof(arr[0]);   // compute size

    ArrayQueue q;                           // create queue
    for (int i = 0; i < n; i++) q.enqueue(arr[i]); // load elements

    selectionSortUsingQueue(q, n);          // sort

    cout << "Sorted (array-queue selection sort): "; // print header
    while (!q.isEmpty()) cout << q.dequeue() << " "; // print each element
    cout << endl;                           // newline

    return 0;                               // exit
}