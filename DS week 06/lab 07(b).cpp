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

// Function to print and count leaf nodes
int printAndCountLeaves(Node* root) {
    // Base case: if the tree is empty, there are 0 leaves
    if (root == nullptr) {
        return 0; 
    }

    // Check if the current node is a leaf node
    // (It has no left child AND no right child)
    if (root->left == nullptr && root->right == nullptr) {
        cout << root->data << " "; // Print the leaf node's data
        return 1;                  // Return 1 to add to the total count
    }

    // If it's not a leaf, recursively check both left and right subtrees
    // and add their counts together
    int leftLeaves = printAndCountLeaves(root->left);   // Count leaves in left subtree
    int rightLeaves = printAndCountLeaves(root->right); // Count leaves in right subtree
    
    return leftLeaves + rightLeaves; // Return the total count for this branch
}

int main() {
    // Constructing a sample Binary Search Tree:
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

    cout << "Leaf Nodes are: ";
    int totalLeaves = printAndCountLeaves(root); // Call the function
    
    cout << "\nTotal Leaf Nodes: " << totalLeaves << endl; // Print final count

    return 0;
}