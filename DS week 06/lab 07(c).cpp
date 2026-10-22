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

// Helper function to find the node with the minimum value in a tree
// Used in Case 3 (Node with two children) to find the Inorder Successor
Node* findMin(Node* root) {
    while (root->left != nullptr) { // Keep traversing left until we can't anymore
        root = root->left;          // Move pointer to the left child
    }
    return root;                    // Return the leftmost (smallest) node
}

// Function to delete a node from the BST
Node* deleteNode(Node* root, int key) {
    // Base case: if the tree is empty, return null
    if (root == nullptr) {
        return root; 
    }

    // Step 1: Search for the node to delete
    if (key < root->data) {
        // Key is smaller, go to left subtree
        root->left = deleteNode(root->left, key);
    } 
    else if (key > root->data) {
        // Key is larger, go to right subtree
        root->right = deleteNode(root->right, key);
    } 
    else {
        // Step 2: Node found! Handle the 3 possibilities for deletion:

        // Possibility 1 & 2: Node with NO children (leaf) OR node with ONE child
        if (root->left == nullptr) {
            Node* temp = root->right; // Store right child (or null if leaf)
            delete root;              // Delete the current node
            return temp;              // Return right child to replace current node
        } 
        else if (root->right == nullptr) {
            Node* temp = root->left;  // Store left child
            delete root;              // Delete the current node
            return temp;              // Return left child to replace current node
        }

        // Possibility 3: Node with TWO children
        // Find the Inorder Successor (smallest node in the right subtree)
        Node* temp = findMin(root->right); 
        
        // Copy the successor's data to the current node
        root->data = temp->data; 
        
        // Delete the successor node from the right subtree
        root->right = deleteNode(root->right, temp->data); 
    }
    return root; // Return the modified tree root
}

// Helper function to print tree in standard Inorder (Left, Node, Right) to verify deletions
void printInOrder(Node* root) {
    if (root == nullptr) return;
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

int main() {
    // Constructing a sample BST:
    //        50
    //       /  \
    //     30    70
    //    /  \  /  \
    //  20  40 60  80
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    cout << "Original Tree (In-Order): ";
    printInOrder(root);
    cout << endl << endl;

    // --- TEST CASE 1: Delete a Leaf Node (no children) ---
    cout << "Deleting 20 (Leaf node)..." << endl;
    root = deleteNode(root, 20);
    cout << "Tree after deleting 20: ";
    printInOrder(root);
    cout << endl << endl;

    // --- TEST CASE 2: Delete a Node with One Child ---
    // (Let's delete 30, it now only has a right child 40)
    cout << "Deleting 30 (Node with one child)..." << endl;
    root = deleteNode(root, 30);
    cout << "Tree after deleting 30: ";
    printInOrder(root);
    cout << endl << endl;

    // --- TEST CASE 3: Delete a Node with Two Children ---
    // (Deleting 50, the root, which has two children)
    cout << "Deleting 50 (Node with two children)..." << endl;
    root = deleteNode(root, 50);
    cout << "Tree after deleting 50: ";
    printInOrder(root);
    cout << endl << endl;

    return 0;
}