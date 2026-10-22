#include <iostream>                 // include iostream for input/output
using namespace std;                // allow std namespace

// ---------- Node for linked stack ----------
struct Node {                       // structure representing a node
    int data;                       // data stored in node
    Node* next;                     // pointer to next node
    Node(int d) : data(d), next(nullptr) {} // constructor initializes data and next
};

// ---------- Linked-List-based Stack ----------
class LinkedStack {                 // class implementing stack via linked list
private:                            // private members
    Node* top;                      // pointer to top node
public:                             // public members
    LinkedStack() { top = nullptr; } // constructor: stack starts empty
    ~LinkedStack() { while (!isEmpty()) pop(); } // destructor: free all nodes

    bool isEmpty() { return top == nullptr; }    // empty if top is null

    void push(int x) {              // push function
        Node* n = new Node(x);      // create new node with value x
        n->next = top;              // new node points to old top
        top = n;                    // update top to new node
    }

    int pop() {                     // pop function
        if (isEmpty()) { cout << "Stack Underflow\n"; return -1; } // handle empty
        int val = top->data;        // save top's data
        Node* temp = top;           // save node to delete
        top = top->next;            // move top pointer down
        delete temp;                // delete old top node
        return val;                 // return saved value
    }

    int peek() {                    // peek function
        if (isEmpty()) return -1;   // return sentinel if empty
        return top->data;           // return top data
    }
};

// ---------- Queue using Two Linked Stacks ----------
class QueueUsingStacks {            // queue implementation using two linked stacks
private:                            // private members
    LinkedStack s1, s2;             // s1 for enqueue, s2 for dequeue
public:                             // public members
    void enqueue(int x) {           // enqueue function
        s1.push(x);                 // push onto s1
        cout << x << " enqueued\n"; // confirmation message
    }

    int dequeue() {                 // dequeue function
        if (s1.isEmpty() && s2.isEmpty()) {   // both empty => queue empty
            cout << "Queue is empty\n";       // report
            return -1;                        // return sentinel
        }
        if (s2.isEmpty())                     // if s2 empty, transfer from s1
            while (!s1.isEmpty())             // while s1 not empty
                s2.push(s1.pop());            // move all elements to s2
        return s2.pop();                      // pop from s2 (oldest first)
    }

    int front() {                   // front function
        if (s1.isEmpty() && s2.isEmpty()) return -1;  // empty case
        if (s2.isEmpty())                             // if s2 empty, transfer
            while (!s1.isEmpty())                     // while s1 not empty
                s2.push(s1.pop());                    // move all
        return s2.peek();                             // return front element
    }

    bool isEmpty() { return s1.isEmpty() && s2.isEmpty(); } // empty check
};

// ---------- Main ----------
int main() {                        // entry point
    QueueUsingStacks q;             // create queue
    q.enqueue(5);                   // enqueue 5
    q.enqueue(15);                  // enqueue 15
    q.enqueue(25);                  // enqueue 25

    cout << "Dequeued: " << q.dequeue() << endl;   // -> 5
    cout << "Front: "    << q.front()   << endl;   // -> 15

    q.enqueue(35);                                  // enqueue 35
    cout << "Dequeued: " << q.dequeue() << endl;   // -> 15
    cout << "Dequeued: " << q.dequeue() << endl;   // -> 25
    cout << "Dequeued: " << q.dequeue() << endl;   // -> 35
    cout << "Dequeued: " << q.dequeue() << endl;   // empty

    return 0;                       // exit
}