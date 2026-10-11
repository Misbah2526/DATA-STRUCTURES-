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

// Insert node at the end
void insert_end()
{
    Node *p = new Node;

    cout << "Enter data: ";
    cin >> p->data;

    p->next = NULL;
    p->prev = NULL;

    if (first == NULL)
    {
        first = last = p;
    }
    else
    {
        last->next = p;
        p->prev = last;
        last = p;
    }
}

// Traverse in forward direction
void forward()
{
    Node *p;

    cout << "\nForward direction: ";

    for (p = first; p != NULL; p = p->next)
    {
        cout << p->data << " ";
    }
}

// Traverse in backward direction
void backward()
{
    Node *p;

    cout << "\nBackward direction: ";

    for (p = last; p != NULL; p = p->prev)
    {
        cout << p->data << " ";
    }
}

int main()
{
    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    // Create nodes
    for (int i = 0; i < n; i++)
    {
        insert_end();
    }

    // Traverse forward
    forward();

    // Traverse backward
    backward();

    return 0;
}