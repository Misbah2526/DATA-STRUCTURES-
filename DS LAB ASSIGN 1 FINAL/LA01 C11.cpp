#include <iostream>
#include <string>
using namespace std;

struct NodeType {
    string name;
    NodeType *next;
    NodeType *prev;
};

NodeType *first = NULL, *last = NULL;

void insert_end(string val) {
    NodeType *p = new NodeType;
    p->name = val;
    p->next = NULL;
    p->prev = NULL;
    
    if (first == NULL) {
        first = last = p;
    } else {
        last->next = p;
        p->prev = last;
        last = p;
    }
}

// Swap values from both ends toward center
void swapEndsTowardsCenter() {
    if (first == NULL || first == last) return;
    
    NodeType *left = first;
    NodeType *right = last;
    
    while (left != right && left->prev != right) {
        swap(left->name, right->name);
        left = left->next;
        right = right->prev;
    }
}

void display() {
    NodeType *p = first;
    while (p != NULL) {
        cout << p->name;
        if (p->next != NULL) cout << " <-> ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    insert_end("Alice"); insert_end("Bob"); insert_end("Charlie");
    insert_end("Dana"); insert_end("Eva"); insert_end("Frank");
    
    cout << "Original: "; display();
    swapEndsTowardsCenter();
    cout << "After: "; display();
    
    return 0;
}