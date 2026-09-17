#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

// Insert at end
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

// Find multiple occurrences
void findOccurrences(Node* first, int value)
{
    Node* p = first;
    int position = 1;
    int count = 0;

    while (p != NULL)
    {
        if (p->data == value)
        {
            cout << "Found at position: " << position << endl;
            count++;
        }

        p = p->next;
        position++;
    }

    if (count == 0)
    {
        cout << "Value not found." << endl;
    }
    else
    {
        cout << "Total occurrences: " << count << endl;
    }
}

// Display list
void display(Node* first)
{
    Node* p = first;

    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

int main()
{
    Node* first = NULL;

    insert(first, 10);
    insert(first, 20);
    insert(first, 10);
    insert(first, 30);
    insert(first, 10);
    insert(first, 40);

    cout << "Linked List: ";
    display(first);

    int value;

    cout << "\nEnter value to search: ";
    cin >> value;

    findOccurrences(first, value);

    return 0;
}