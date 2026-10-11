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

// Delete node with given key
void deleteNode(NodeT*& pNode, int givenKey) {

    if (pNode == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    NodeT* p;
    NodeT* q;
    NodeT* q1;

    q = pNode;

    // Find the node with givenKey
    do {
        q1 = q;
        q = q->next;

        if (q->key == givenKey)
            break;

    } while (q != pNode);

    // Check if key was found
    if (q->key == givenKey) {

        // Only one node in the list
        if (q == q->next) {

            pNode = NULL;
        }
        else {

            // Remove q from the list
            q1->next = q->next;

            // If q is the first node
            if (q == pNode) {
                pNode = q1;
            }
        }

        // Free memory
        delete q;

        cout << "Node deleted successfully." << endl;
    }
    else {
        cout << "Key not found." << endl;
    }
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

    // First node
    pNode = p1;

    // Display original list
    cout << "Original list: ";
    display(pNode);

    // Ask user for key
    int givenKey;

    cout << "Enter key to delete: ";
    cin >> givenKey;

    // Delete node
    deleteNode(pNode, givenKey);

    // Display list after deletion
    cout << "List after deletion: ";
    display(pNode);

    return 0;
}