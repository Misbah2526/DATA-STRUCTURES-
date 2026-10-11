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

// Delete even or odd valued nodes
// even = true  -> delete even values
// even = false -> delete odd values
void deleteEvenOdd(Node*& head, bool even)
{
    while (head != NULL &&
           ((even && head->data % 2 == 0) ||
            (!even && head->data % 2 != 0)))
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    if (head == NULL)
        return;

    Node* p = head;

    while (p->next != NULL)
    {
        if ((even && p->next->data % 2 == 0) ||
            (!even && p->next->data % 2 != 0))
        {
            Node* temp = p->next;
            p->next = temp->next;
            delete temp;
        }
        else
        {
            p = p->next;
        }
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
    insert(head, 15);
    insert(head, 20);
    insert(head, 25);
    insert(head, 30);
    insert(head, 35);

    cout << "Original list: ";
    display(head);

    // Delete even values
    deleteEvenOdd(head, true);

    cout << "After deleting even values: ";
    display(head);

    return 0;
}