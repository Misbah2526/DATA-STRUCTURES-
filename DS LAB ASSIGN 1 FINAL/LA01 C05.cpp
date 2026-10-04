#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to find middle node
Node* findMiddle(Node* head) {
    if (head == NULL)
        return NULL;

    Node* slow = head;
    Node* fast = head;

    // Find left middle for even number of nodes
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// Insert node at end
void insertEnd(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

int main() {
    Node* head = NULL;

    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);
   

    Node* middle = findMiddle(head);

    if (middle != NULL)
        cout << "Middle node: " << middle->data;

    return 0;
}