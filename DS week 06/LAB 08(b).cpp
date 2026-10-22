#include <iostream>
#include <queue> // Required for level order traversal
using namespace std;

// Structure for a Tree Node
struct Node {
    int data;           // Stores the data value
    Node* left;         // Pointer to left child
    Node* right;        // Pointer to right child

    // Constructor to initialize a new node
    Node(int val) {
        data = val;     // Set data
        left = nullptr; // Set left to null
        right = nullptr;// Set right to null
    }
};

// Function to perform Level Order Traversal
void printLevelOrder(Node* root) {
    // Base case: if the tree is empty, do nothing
    if (root == nullptr) return;

    // Create a queue to hold nodes for processing
    queue<Node*> q;

    // Push the root node into the queue to start
    q.push(root);

    // Continue processing while there are nodes in the queue
    while (!q.empty()) {
        // Get the front node from the queue
        Node* current = q.front();
        
        // Remove the processed node from the queue
        q.pop();

        // Print the data of the current node
        cout << current->data << " ";

        // If the left child exists, push it to the queue for later processing
        if (current->left != nullptr) {
            q.push(current->left);
        }

        // If the right child exists, push it to the queue for later processing
        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
}

int main() {
    // Manually constructing a balanced tree to represent an AVL tree
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

    cout << "Level Order Traversal of AVL Tree: ";
    printLevelOrder(root); // Call the function
    cout << endl;

    return 0;
}