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

// Merge two lists into third list
void mergeLists(Node* first1, Node* first2, Node*& first3)
{
    Node* p = first1;

    while (p != NULL)
    {
        insert(first3, p->data);
        p = p->next;
    }

    p = first2;

    while (p != NULL)
    {
        insert(first3, p->data);
        p = p->next;
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
    Node* first1 = NULL;
    Node* first2 = NULL;
    Node* first3 = NULL;

    // First list
    insert(first1, 10);
    insert(first1, 20);
    insert(first1, 30);

    // Second list
    insert(first2, 40);
    insert(first2, 50);
    insert(first2, 60);

    cout << "First List: ";
    display(first1);

    cout << "\nSecond List: ";
    display(first2);

    // Merge
    mergeLists(first1, first2, first3);

    cout << "\nThird List after merging: ";
    display(first3);

    return 0;
}