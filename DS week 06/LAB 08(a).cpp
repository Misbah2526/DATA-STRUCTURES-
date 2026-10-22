#include <iostream>
#include <algorithm> // Required for the max() function
using namespace std;

// Structure for an AVL Tree Node
struct Node {
    int data;           // Stores the data value
    Node* left;         // Pointer to the left child
    Node* right;        // Pointer to the right child
    int height;         // Stores the height of the node

    // Constructor to initialize a new node
    Node(int val) {
        data = val;     // Set the data
        left = nullptr; // Initialize left child as null
        right = nullptr;// Initialize right child as null
        height = 1;     // A new node is initially at height 1
    }
};

// Utility function to get the height of a node
int getHeight(Node* node) {
    if (node == nullptr) return 0; // If node is null, height is 0
    return node->height;           // Otherwise, return the stored height
}

// Utility function to calculate the Balance Factor
// Balance Factor = height(left subtree) - height(right subtree)
int getBalance(Node* node) {
    if (node == nullptr) return 0; // If node is null, balance is 0
    return getHeight(node->left) - getHeight(node->right); // Calculate and return balance
}

// --- ROTATION 1: Right Rotation (LL Case) ---
Node* rotateRight(Node* y) {
    Node* x = y->left;      // x is the left child of y
    Node* T2 = x->right;    // T2 is the right child of x (which will move)

    // Perform rotation
    x->right = y;           // x becomes the new root, y becomes its right child
    y->left = T2;           // T2 becomes the left child of y

    // Update heights (must update y first, as it is now lower)
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;               // Return the new root (x)
}

// --- ROTATION 2: Left Rotation (RR Case) ---
Node* rotateLeft(Node* x) {
    Node* y = x->right;     // y is the right child of x
    Node* T2 = y->left;     // T2 is the left child of y (which will move)

    // Perform rotation
    y->left = x;            // y becomes the new root, x becomes its left child
    x->right = T2;          // T2 becomes the right child of x

    // Update heights (must update x first, as it is now lower)
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;               // Return the new root (y)
}

// Function to insert a node and automatically apply necessary rotations
Node* insert(Node* node, int key) {
    // 1. Perform standard BST insertion
    if (node == nullptr) return new Node(key); // Create new node if empty

    if (key < node->data) {
        node->left = insert(node->left, key);  // Insert in left subtree
    } else if (key > node->data) {
        node->right = insert(node->right, key);// Insert in right subtree
    } else {
        return node; // Duplicate keys not allowed, return unchanged
    }

    // 2. Update height of this ancestor node
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // 3. Get the balance factor to check if this node became unbalanced
    int balance = getBalance(node);

    // 4. If unbalanced, apply rotations (4 Cases)

    // Case 1: Left Left (LL) -> Apply Right Rotation
    if (balance > 1 && key < node->left->data) {
        return rotateRight(node);
    }

    // Case 2: Right Right (RR) -> Apply Left Rotation
    if (balance < -1 && key > node->right->data) {
        return rotateLeft(node);
    }

    // Case 3: Left Right (LR) -> Apply Left on child, then Right on node
    if (balance > 1 && key > node->left->data) {
        node->left = rotateLeft(node->left); // First, rotate left on left child
        return rotateRight(node);            // Then, rotate right on current node
    }

    // Case 4: Right Left (RL) -> Apply Right on child, then Left on node
    if (balance < -1 && key < node->right->data) {
        node->right = rotateRight(node->right); // First, rotate right on right child
        return rotateLeft(node);                // Then, rotate left on current node
    }

    return node; // Return the (potentially new) root of this subtree
}

// Helper function to print the tree in Pre-order (Root, Left, Right)
void printPreOrder(Node* root) {
    if (root == nullptr) return;       // Base case
    cout << root->data << " ";         // Print node
    printPreOrder(root->left);         // Go left
    printPreOrder(root->right);        // Go right
}

int main() {
    Node* root = nullptr; // Initialize empty tree

    // Inserting nodes. The AVL insert function will automatically
    // figure out which rotations to apply to keep the tree balanced.
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30); // Triggers RR Rotation (Left Rotation)
    
    root = insert(root, 40);
    root = insert(root, 50); 
    
    root = insert(root, 25); // Triggers RL Rotation (Right-Left Rotation)

    cout << "Pre-order traversal of constructed AVL tree:\n";
    printPreOrder(root);
    cout << endl;

    return 0;
}