#include <iostream>                 // include iostream for cout
using namespace std;                // allow std namespace

#define MAX 100                     // max capacity of queue

// ---------- Array-based Circular Queue ----------
class ArrayQueue {                  // circular queue class using array
private:                            // private members
    int arr[MAX];                   // array holding queue elements
    int front, rear, count;         // front index, rear index, number of items
public:                             // public members
    ArrayQueue() { front = 0; rear = -1; count = 0; }  // constructor

    bool isEmpty() { return count == 0; }   // empty if count is 0
    bool isFull()  { return count == MAX; } // full if count equals MAX

    void enqueue(int x) {           // enqueue function
        if (isFull()) { cout << "Queue Full\n"; return; } // handle full
        rear = (rear + 1) % MAX;    // advance rear circularly
        arr[rear] = x;              // store new value
        count++;                    // increase count
    }

    int dequeue() {                 // dequeue function
        if (isEmpty()) { cout << "Queue Empty\n"; return -1; } // handle empty
        int val = arr[front];       // save front value
        front = (front + 1) % MAX;  // advance front circularly
        count--;                    // decrease count
        return val;                 // return saved value
    }

    int getFront() { return isEmpty() ? -1 : arr[front]; } // return front or -1
    int size()     { return count; }                        // return current size
};

// ---------- Stack using Two Queues ----------
class StackUsingQueues {            // stack built from two queues
private:                            // private members
    ArrayQueue q1, q2;              // two queues
public:                             // public members
    // Push: enqueue into q2, move all from q1 to q2, then swap
    void push(int x) {              // push function
        q2.enqueue(x);              // add new element to q2
        while (!q1.isEmpty())       // while q1 has elements
            q2.enqueue(q1.dequeue()); // move them to q2 (after x)
        // swap q1 and q2
        ArrayQueue temp = q1;       // copy q1 into temp
        q1 = q2;                    // assign q2 to q1
        q2 = temp;                  // assign old q1 (in temp) to q2
        cout << x << " pushed\n";   // confirmation
    }

    int pop() {                     // pop function
        if (q1.isEmpty()) { cout << "Stack empty\n"; return -1; } // handle empty
        return q1.dequeue();        // remove from front of q1 (top of stack)
    }

    int top() { return q1.getFront(); }   // return top of stack
    bool isEmpty() { return q1.isEmpty(); } // empty check
};

// ---------- Main ----------
int main() {                        // entry point
    StackUsingQueues s;             // create stack
    s.push(10);                     // push 10
    s.push(20);                     // push 20
    s.push(30);                     // push 30

    cout << "Popped: " << s.pop() << endl;   // -> 30
    cout << "Top: "    << s.top() << endl;   // -> 20

    s.push(40);                              // push 40
    cout << "Popped: " << s.pop() << endl;   // -> 40
    cout << "Popped: " << s.pop() << endl;   // -> 20
    cout << "Popped: " << s.pop() << endl;   // -> 10
    cout << "Popped: " << s.pop() << endl;   // empty

    return 0;                       // exit
}