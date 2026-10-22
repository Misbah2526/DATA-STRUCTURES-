#include <iostream>                 // include iostream
using namespace std;                // allow std namespace

// ---------- Node for linked queue ----------
struct Node {                       // node structure
    int data;                       // data
    Node* next;                     // next pointer
    Node(int d) : data(d), next(nullptr) {} // constructor
};

// ---------- Linked-List-based Queue ----------
class LinkedQueue {                 // queue via linked list
private:                            // private members
    Node *front, *rear;             // pointers to front and rear
public:                             // public members
    LinkedQueue() { front = rear = nullptr; }   // constructor
    ~LinkedQueue() { while (!isEmpty()) dequeue(); } // destructor

    // Disable default copy to avoid double-free (we use move instead)
    LinkedQueue(const LinkedQueue&) = delete;               // delete copy ctor
    LinkedQueue& operator=(const LinkedQueue&) = delete;    // delete copy assign

    // Move constructor: steals pointers from another queue
    LinkedQueue(LinkedQueue&& other) noexcept {             // move ctor
        front = other.front;                                // copy front pointer
        rear  = other.rear;                                 // copy rear pointer
        other.front = other.rear = nullptr;                 // clear other
    }

    // Move assignment: releases current then steals pointers
    LinkedQueue& operator=(LinkedQueue&& other) noexcept {  // move assign
        if (this != &other) {                               // self-check
            while (!isEmpty()) dequeue();                   // free current nodes
            front = other.front;                            // steal front
            rear  = other.rear;                             // steal rear
            other.front = other.rear = nullptr;             // clear other
        }
        return *this;                                       // return this
    }

    bool isEmpty() { return front == nullptr; }             // empty check

    void enqueue(int x) {                                   // enqueue function
        Node* n = new Node(x);                              // create node
        if (rear == nullptr) { front = rear = n; return; }  // if empty, front=rear=n
        rear->next = n;                                     // attach after rear
        rear = n;                                           // update rear
    }

    int dequeue() {                                         // dequeue function
        if (isEmpty()) { cout << "Queue Empty\n"; return -1; } // handle empty
        int val = front->data;                              // save data
        Node* temp = front;                                 // save node to delete
        front = front->next;                                // move front
        if (front == nullptr) rear = nullptr;               // if became empty, reset rear
        delete temp;                                        // delete old front
        return val;                                         // return data
    }

    int getFront() { return isEmpty() ? -1 : front->data; } // return front value
};

// ---------- Stack using Two Linked Queues ----------
class StackUsingQueues {            // stack built from two linked queues
private:                            // private members
    LinkedQueue q1, q2;             // two queues
public:                             // public members
    void push(int x) {              // push function
        q2.enqueue(x);              // add new element to q2
        while (!q1.isEmpty())       // move all q1 elements to q2
            q2.enqueue(q1.dequeue()); // preserve order after x
        // safely swap using move (LinkedQueue has move ctor/assign)
        LinkedQueue temp = move(q1); // move q1 to temp
        q1 = move(q2);               // move q2 to q1
        q2 = move(temp);             // move temp to q2
        cout << x << " pushed\n";    // confirmation
    }

    int pop() {                     // pop function
        if (q1.isEmpty()) { cout << "Stack empty\n"; return -1; } // handle empty
        return q1.dequeue();        // remove front of q1 (stack top)
    }

    int top() { return q1.getFront(); }   // return top
    bool isEmpty() { return q1.isEmpty(); } // empty check
};

// ---------- Main ----------
int main() {                        // entry point
    StackUsingQueues s;             // create stack
    s.push(100);                    // push 100
    s.push(200);                    // push 200
    s.push(300);                    // push 300

    cout << "Popped: " << s.pop() << endl;   // -> 300
    cout << "Top: "    << s.top() << endl;   // -> 200

    s.push(400);                              // push 400
    cout << "Popped: " << s.pop() << endl;   // -> 400
    cout << "Popped: " << s.pop() << endl;   // -> 200
    cout << "Popped: " << s.pop() << endl;   // -> 100
    cout << "Popped: " << s.pop() << endl;   // empty

    return 0;                       // exit
}