#include <iostream>
using namespace std;

// Structure for a tree node
struct Node {
    int data;           // Holds the node's value
    Node* left;         // Pointer to left child
    Node* right;        // Pointer to right child

    // Constructor to initialize a new node
    Node(int val) {
        data = val;     // Set the node's data
        left = nullptr; // Initialize left child as null
        right = nullptr;// Initialize right child as null
    }
};

// 1. Pre Order Traversal (NRL - Node, Right, Left)
void preOrderNRL(Node* root) {
    if (root == nullptr) return; // Base case: stop if current node is null
    cout << root->data << " ";   // Process Node first (N)
    preOrderNRL(root->right);    // Traverse Right subtree second (R)
    preOrderNRL(root->left);     // Traverse Left subtree last (L)
}

// 2. Post Order Traversal (RLN - Right, Left, Node)
void postOrderRLN(Node* root) {
    if (root == nullptr) return; // Base case: stop if current node is null
    postOrderRLN(root->right);   // Traverse Right subtree first (R)
    postOrderRLN(root->left);    // Traverse Left subtree second (L)
    cout << root->data << " ";   // Process Node last (N)
}

// 3. In Order Traversal (RNL - Right, Node, Left)
void inOrderRNL(Node* root) {
    if (root == nullptr) return; // Base case: stop if current node is null
    inOrderRNL(root->right);     // Traverse Right subtree first (R)
    cout << root->data << " ";   // Process Node second (N)
    inOrderRNL(root->left);      // Traverse Left subtree last (L)
}

int main() {
    // Constructing a sample tree:
    //        10
    //       /  \
    //      5    15
    //     / \   / \
    //    3   7 12  20
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->left = new Node(12);
    root->right->right = new Node(20);

    cout << "Pre Order (NRL):  ";
    preOrderNRL(root); // Call NRL traversal
    cout << endl;

    cout << "Post Order (RLN): ";
    postOrderRLN(root); // Call RLN traversal
    cout << endl;

    cout << "In Order (RNL):   ";
    inOrderRNL(root); // Call RNL traversal
    cout << endl;

    return 0;
}