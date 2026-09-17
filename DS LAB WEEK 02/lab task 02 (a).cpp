#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

// Insert node at end
void insert(Node*& first, int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (first == NULL)
    {
        first = newNode;
    }
    else
    {
        Node* p = first;

        while (p->next != NULL)
        {
            p = p->next;
        }

        p->next = newNode;
    }
}

// Display normally
void display(Node* first)
{
    Node* p = first;

    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

// Reverse using loop
void reverseLoop(Node* first)
{
    int arr[100];
    int i = 0;

    Node* p = first;

    while (p != NULL)
    {
        arr[i] = p->data;
        i++;
        p = p->next;
    }

    for (i = i - 1; i >= 0; i--)
    {
        cout << arr[i] << " ";
    }
}

// Reverse using recursion
void reverseRecursive(Node* p)
{
    if (p == NULL)
        return;

    reverseRecursive(p->next);

    cout << p->data << " ";
}

int main()
{
    Node* first = NULL;

    insert(first, 10);
    insert(first, 20);
    insert(first, 30);
    insert(first, 40);
    insert(first, 50);

    cout << "Original List: ";
    display(first);

    cout << "\n\nReverse using Loop: ";
    reverseLoop(first);

    cout << "\nReverse using Recursion: ";
    reverseRecursive(first);

    return 0;
}