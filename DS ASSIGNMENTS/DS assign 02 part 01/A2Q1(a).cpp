#include <iostream>                 // include iostream for cin/cout
using namespace std;                // allow std namespace (cout, endl, etc.)

#define MAX 100                     // define maximum capacity for the stack array


class ArrayStack {                  // class representing a stack using an array
private:                            // private members (hidden from outside)
    int arr[MAX];                   // array to hold stack elements
    int top;                        // index of the current top element
public:                             // public members (accessible outside)
    ArrayStack() { top = -1; }      // constructor initializes top to -1 (empty stack)

    bool isEmpty() { return top == -1; }   // check if stack is empty
    bool isFull()  { return top == MAX - 1; } // check if stack is full

    void push(int x) {              // push function: add element on top
        if (isFull()) { cout << "Stack Overflow\n"; return; } // handle overflow
        arr[++top] = x;             // increment top then store x at new top
    }

    int pop() {                     // pop function: remove and return top element
        if (isEmpty()) { cout << "Stack Underflow\n"; return -1; } // handle underflow
        return arr[top--];          // return top value, then decrement top
    }

    int peek() {                    // peek function: return top without removing
        if (isEmpty()) return -1;   // if empty, return -1 sentinel
        return arr[top];            // otherwise return the top value
    }
};


class QueueUsingStacks {            // class representing a queue built from two stacks
private:                            // private members
    ArrayStack s1;                  // s1 used for enqueue operations
    ArrayStack s2;                  // s2 used for dequeue operations
public:                             // public members
    // Enqueue: simply push onto s1
    void enqueue(int x) {           // enqueue function
        s1.push(x);                 // push new element onto s1
        cout << x << " enqueued\n"; // print confirmation
    }

    // Dequeue: move all from s1 to s2 (once), then pop from s2
    int dequeue() {                 // dequeue function
        if (s1.isEmpty() && s2.isEmpty()) {   // if both stacks empty
            cout << "Queue is empty\n";       // report empty queue
            return -1;                        // return sentinel
        }
        if (s2.isEmpty()) {                   // if s2 is empty, transfer from s1
            while (!s1.isEmpty())             // loop while s1 has elements
                s2.push(s1.pop());            // move each element from s1 to s2
        }
        return s2.pop();                      // pop from s2 (FIFO order preserved)
    }

    int front() {                   // front function: return front element without removing
        if (s1.isEmpty() && s2.isEmpty()) return -1;   // if both empty, return -1
        if (s2.isEmpty()) {                          // if s2 empty, need to transfer
            while (!s1.isEmpty())                    // move all elements
                s2.push(s1.pop());                   // from s1 to s2
        }
        return s2.peek();                            // return top of s2 (front of queue)
    }

    bool isEmpty() { return s1.isEmpty() && s2.isEmpty(); } // queue empty if both stacks empty
};


int main() {                        // program entry point
    QueueUsingStacks q;             // create queue object

    q.enqueue(10);                  // enqueue 10
    q.enqueue(20);                  // enqueue 20
    q.enqueue(30);                  // enqueue 30

    cout << "Dequeued: " << q.dequeue() << endl;   // dequeue -> 10
    cout << "Front: "    << q.front()   << endl;   // front is now 20

    q.enqueue(40);                                  // enqueue 40
    cout << "Dequeued: " << q.dequeue() << endl;   // dequeue -> 20
    cout << "Dequeued: " << q.dequeue() << endl;   // dequeue -> 30
    cout << "Dequeued: " << q.dequeue() << endl;   // dequeue -> 40
    cout << "Dequeued: " << q.dequeue() << endl;   // queue empty

    return 0;                       // exit program
}