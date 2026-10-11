#include <iostream>
using namespace std;

struct NodeT {
    int key;
    NodeT* next;
};

// Display circular linked list
void display(NodeT* pNode) {
    if (pNode == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    NodeT* p = pNode;

    do {
        cout << p->key << " ";
        p = p->next;
    } while (p != pNode);

    cout << endl;
}

// Insert before a node with givenKey
void insertBefore(NodeT*& pNode, int newKey, int givenKey) {

    // Create new node
    NodeT* p = new NodeT;
    p->key = newKey;

    // Empty list
    if (pNode == NULL) {
        p->next = p;
        pNode = p;
        return;
    }

    NodeT* q;
    NodeT* q1;

    q1 = NULL;
    q = pNode;

    // Find the node with givenKey
    do {
        q1 = q;
        q = q->next;

        if (q->key == givenKey)
            break;

    } while (q != pNode);

    // Key found
    if (q->key == givenKey) {

        q1->next = p;
        p->next = q;

        // If inserting before the first node,
        // update pNode
        if (q == pNode) {
            pNode = p;
        }
    }
    else {
        cout << "Key not found." << endl;
        delete p;
    }
}

// Insert after a node with givenKey
void insertAfter(NodeT* pNode, int newKey, int givenKey) {

    // Create new node
    NodeT* p = new NodeT;
    p->key = newKey;

    if (pNode == NULL) {
        p->next = p;
        pNode = p;
        return;
    }

    NodeT* q;
    q = pNode;

    // Find the node with givenKey
    do {
        if (q->key == givenKey)
            break;

        q = q->next;

    } while (q != pNode);

    // Key found
    if (q->key == givenKey) {
        p->next = q->next;
        q->next = p;
    }
    else {
        cout << "Key not found." << endl;
        delete p;
    }
}

int main() {

    // Create circular linked list
    NodeT* pNode = NULL;

    NodeT* p1 = new NodeT;
    NodeT* p2 = new NodeT;
    NodeT* p3 = new NodeT;

    p1->key = 10;
    p2->key = 20;
    p3->key = 30;

    p1->next = p2;
    p2->next = p3;
    p3->next = p1;

    pNode = p1;

    // Original list
    cout << "Original list: ";
    display(pNode);

    // Insert 15 before 20
    insertBefore(pNode, 15, 20);

    cout << "After inserting 15 before 20: ";
    display(pNode);

    // Insert 25 after 20
    insertAfter(pNode, 25, 20);

    cout << "After inserting 25 after 20: ";
    display(pNode);

    return 0;
}