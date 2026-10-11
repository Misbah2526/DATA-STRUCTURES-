#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

// Insert at end
void insert(Node*& head, int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node* p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }

    p->next = newNode;
}

// Delete nodes at even positions
void deleteEvenPositions(Node*& head)
{
    if (head == NULL)
        return;

    Node* p = head;

    while (p != NULL && p->next != NULL)
    {
        Node* temp = p->next;

        p->next = temp->next;

        delete temp;

        p = p->next;
    }
}

// Display
void display(Node* head)
{
    Node* p = head;

    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }

    cout << endl;
}

int main()
{
    Node* head = NULL;

    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    insert(head, 40);
    insert(head, 50);
    insert(head, 60);

    cout << "Original list: ";
    display(head);

    deleteEvenPositions(head);

    cout << "After deleting even positions: ";
    display(head);

    return 0;
}