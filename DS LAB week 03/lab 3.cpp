#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* prev;
    Node* next;
};

struct List
{
    Node* first;
    Node* last;
};

// Initialize list
void initialize(List& L)
{
    L.first = NULL;
    L.last = NULL;
}

// Insert before the first node
void insertBeforeFirst(List& L, int value)
{
    Node* p = new Node;
    p->data = value;

    if (L.first == NULL)
    {
        // Empty list
        L.first = L.last = p;
        p->next = p->prev = NULL;
    }
    else
    {
        // Non-empty list
        p->next = L.first;
        p->prev = NULL;

        L.first->prev = p;
        L.first = p;
    }
}

// Insert after the last node
void insertAfterLast(List& L, int value)
{
    Node* p = new Node;
    p->data = value;

    if (L.first == NULL)
    {
        // Empty list
        L.first = L.last = p;
        p->next = p->prev = NULL;
    }
    else
    {
        // Non-empty list
        p->next = NULL;
        p->prev = L.last;

        L.last->next = p;
        L.last = p;
    }
}

// Insert after a node with a given key
void insertAfterKey(List& L, int key, int value)
{
    Node* q = L.first;

    // Find the node containing the key
    while (q != NULL && q->data != key)
    {
        q = q->next;
    }

    if (q == NULL)
    {
        cout << "Key not found!" << endl;
        return;
    }

    Node* p = new Node;
    p->data = value;

    p->prev = q;
    p->next = q->next;

    if (q->next != NULL)
    {
        q->next->prev = p;
    }

    q->next = p;

    if (L.last == q)
    {
        L.last = p;
    }
}

// Display list from first to last
void displayForward(List L)
{
    Node* temp = L.first;

    cout << "Forward: ";

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

// Display list from last to first
void displayBackward(List L)
{
    Node* temp = L.last;

    cout << "Backward: ";

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }

    cout << endl;
}

int main()
{
    List L;
    initialize(L);

    // Insert before first
    insertBeforeFirst(L, 20);
    insertBeforeFirst(L, 10);

    // Insert after last
    insertAfterLast(L, 30);
    insertAfterLast(L, 40);

    cout << "After inserting before first and after last:" << endl;
    displayForward(L);
    displayBackward(L);

    // Insert after a given key
    insertAfterKey(L, 20, 25);

    cout << "\nAfter inserting 25 after key 20:" << endl;
    displayForward(L);
    displayBackward(L);

    return 0;
}