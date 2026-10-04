#include <iostream>
using namespace std;

struct NodeType {
    int data;
    NodeType *next;
    NodeType *prev;
};

NodeType *first = NULL, *last = NULL;

void insert_end(int val) {
    NodeType *p = new NodeType;
    p->data = val;
    p->next = NULL;
    p->prev = NULL;
    if (first == NULL) first = last = p;
    else { last->next = p; p->prev = last; last = p; }
}

// Pattern: 1 -> 8 -> 3 -> 6 -> 5 -> 4 -> 7 -> 2 -> 9
// First and last remain fixed; alternate swaps toward center
void specialPattern() {
    if (first == NULL || first == last) return;
    
    NodeType *left = first->next;      // start after first
    NodeType *right = last->prev;      // start before last
    
    bool swapFlag = true;
    
    while (left != right && left->prev != right) {
        if (swapFlag) {
            swap(left->data, right->data);
            left = left->next;
            right = right->prev;
        } else {
            left = left->next;
            right = right->prev;
        }
        swapFlag = !swapFlag;
    }
}

void display() {
    NodeType *p = first;
    while (p != NULL) {
        cout << p->data;
        if (p->next != NULL) cout << " -> ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    for (int i = 1; i <= 9; i++) insert_end(i);
    
    cout << "Original: "; display();
    specialPattern();
    cout << "After: "; display();
    
    return 0;
}