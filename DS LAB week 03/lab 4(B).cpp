#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

// Create circular linked list
Node* createList(int n)
{
    Node* head = NULL;
    Node* last = NULL;

    for (int i = 1; i <= n; i++)
    {
        Node* newNode = new Node;
        newNode->data = i;

        if (head == NULL)
        {
            head = newNode;
            last = newNode;
        }
        else
        {
            last->next = newNode;
            last = newNode;
        }
    }

    last->next = head;

    return head;
}

// Josephus function
int josephus(int n, int k)
{
    Node* head = createList(n);

    Node* p = head;
    Node* prev = NULL;

    while (p->next != p)
    {
        // Move k-1 steps
        for (int i = 1; i < k; i++)
        {
            prev = p;
            p = p->next;
        }

        // Delete current node
        prev->next = p->next;

        Node* temp = p;
        p = p->next;

        delete temp;
    }

    int survivor = p->data;

    delete p;

    return survivor;
}

int main()
{
    int n, k;

    cout << "Enter number of people: ";
    cin >> n;

    cout << "Enter counting number: ";
    cin >> k;

    cout << "Survivor is: " << josephus(n, k) << endl;

    return 0;
}