#include <iostream>
using namespace std;

struct NodeT {
    int key;
    NodeT* next;
};

int main() {
    NodeT* pNode = NULL;

    // Create first node
    NodeT* p1 = new NodeT;
    p1->key = 10;

    // Create second node
    NodeT* p2 = new NodeT;
    p2->key = 20;

    // Create third node
    NodeT* p3 = new NodeT;
    p3->key = 30;

    // Make circular connections
    p1->next = p2;
    p2->next = p3;
    p3->next = p1;

    // pNode points to first node
    pNode = p1;

    // --------------------------------
    // Traverse the circular list
    // --------------------------------

    NodeT* p;
    p = pNode;

    cout << "Circular Linked List: ";

    if (p != NULL) {
        do {
            cout << p->key << " ";
            p = p->next;
        } while (p != pNode);
    }

    cout << endl;

    // --------------------------------
    // Search for a key
    // --------------------------------

    int givenKey;

    cout << "Enter key to search: ";
    cin >> givenKey;

    p = pNode;

    if (p != NULL) {
        do {
            if (p->key == givenKey) {
                cout << "Key found: " << p->key << endl;
                cout << "Address of node: " << p << endl;
                return 0;
            }

            p = p->next;

        } while (p != pNode);
    }

    cout << "Key not found." << endl;

    return 0;
}