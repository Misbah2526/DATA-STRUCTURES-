#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

Node *first = NULL;
Node *last = NULL;

void insert_end()
{
    // Take a pointer to hold the address of new node
    Node *p;

    // Allocate memory for new node
    p = new Node;

    // Take data from user
    cout << "Enter the data in node: ";
    cin >> p->data;

    // If list is empty
    if (first == NULL)
    {
        // First and last point to the same node
        first = last = p;

        // No previous or next node
        p->prev = NULL;
        p->next = NULL;
    }
    else
    {
        // Link the old last node with new node
        last->next = p;

        // Link new node back to old last node
        p->prev = last;

        // New node becomes the last node
        last = p;

        // Last node has no next node
        last->next = NULL;
    }
}

void display()
{
    Node *temp = first;

    cout << "\nDoubly Linked List: ";

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    int n;

    cout << "How many nodes do you want to insert? ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        insert_end();
    }

    display();

    return 0;
}