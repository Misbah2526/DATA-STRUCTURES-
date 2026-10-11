#include <iostream>
using namespace std;

struct NodeT {
    int key;
    NodeT* next;
};

// Display the circular linked list
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

// Delete all nodes
void deleteAll(NodeT*& pNode) {

    if (pNode == NULL) {
        cout << "List is already empty." << endl;
        return;
    }

    NodeT* p;
    NodeT* p1;

    p = pNode;

    do {
        p1 = p;
        p = p->next;

        delete p1;

    } while (p != pNode);

    pNode = NULL;

    cout << "All nodes have been deleted." << endl;
}

int main() {

    // Create circular linked list
    NodeT* pNode = NULL;

    NodeT* p1 = new NodeT;
    NodeT* p2 = new NodeT;
    NodeT* p3 = new NodeT;
    NodeT* p4 = new NodeT;

    p1->key = 10;
    p2->key = 20;
    p3->key = 30;
    p4->key = 40;

    // Make circular connections
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p1;

    // Point to first node
    pNode = p1;

    // Display original list
    cout << "Original list: ";
    display(pNode);

    // Delete all nodes
    deleteAll(pNode);

    // Display after deletion
    cout << "List after deleting all nodes: ";
    display(pNode);

    return 0;
}