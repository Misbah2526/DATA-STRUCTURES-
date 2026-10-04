#include <iostream>
using namespace std;

struct NodeType {
    int data;
    NodeType *next;
};

NodeType *pNode = NULL;

// Insert into circular linked list (as per Lab 04 Activity 1)
void insert(int value) {
    NodeType *p = new NodeType;
    p->data = value;
    
    if (pNode == NULL) {
        p->next = p;
        pNode = p;
    } else {
        p->next = pNode->next;
        pNode->next = p;
        pNode = p;
    }
}

// Josephus Problem Solution
int josephus(int N, int M) {
    pNode = NULL;
    
    // Create circle with N persons numbered 1 to N
    for (int i = 1; i <= N; i++) {
        insert(i);
    }
    
    // Start from first person
    NodeType *current = pNode->next;  // points to person 1
    NodeType *prev = pNode;           // points to person N
    
    cout << "Elimination order: ";
    
    // Eliminate until only one remains
    while (current->next != current) {
        // Skip M-1 persons
        for (int count = 1; count < M; count++) {
            prev = current;
            current = current->next;
        }
        
        // Kill Mth person
        cout << current->data << " ";
        prev->next = current->next;
        
        // If current was pNode, update pNode
        if (current == pNode) {
            pNode = prev;
        }
        
        delete current;
        current = prev->next;
    }
    
    cout << endl;
    int survivor = current->data;
    delete current;
    pNode = NULL;
    return survivor;
}

int main() {
    int N, M;
    cout << "Enter total number of persons (N): ";
    cin >> N;
    cout << "Enter skip count (M): ";
    cin >> M;
    
    int safePosition = josephus(N, M);
    cout << "Safe position (survivor): " << safePosition << endl;
    
    return 0;
}