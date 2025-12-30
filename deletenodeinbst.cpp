#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to find the minimum value in a BST
Node* findMin(Node* root) {
    while (root->left) {
        root = root->left;
    }
    return root;
}

// Function to delete a node with given value from BST
Node* deleteNode(Node* root, int x) {
    if (!root) {
        return nullptr;
    }
    
    if (x < root->data) {
        root->left = deleteNode(root->left, x);
    } else if (x > root->data) {
        root->right = deleteNode(root->right, x);
    } else {
        // Node to be deleted found
        
        // Case 1: Node has no children (leaf node)
        if (!root->left && !root->right) {
            delete root;
            return nullptr;
        }
        
        // Case 2: Node has only right child
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        
        // Case 3: Node has only left child
        if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        
        // Case 4: Node has both children
        // Find the inorder successor (minimum in right subtree)
        Node* successor = findMin(root->right);
        root->data = successor->data;  // Replace node's value with successor's value
        root->right = deleteNode(root->right, successor->data);  // Delete the successor
    }
    
    return root;
}

// Helper function to insert a value in BST
Node* insert(Node* root, int val) {
    if (!root) {
        return new Node(val);
    }
    
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    
    return root;
}

// Inorder traversal to display BST
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Driver code
int main() {
    Node* root = nullptr;
    
    // Insert values: 50, 30, 70, 20, 40, 60, 80
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);
    
    cout << "Original BST (Inorder): ";
    inorder(root);
    cout << endl;
    
    // Delete node with value 20 (leaf node)
    root = deleteNode(root, 20);
    cout << "After deleting 20: ";
    inorder(root);
    cout << endl;
    
    // Delete node with value 30 (node with 2 children)
    root = deleteNode(root, 30);
    cout << "After deleting 30: ";
    inorder(root);
    cout << endl;
    
    // Delete node with value 50 (root with 2 children)
    root = deleteNode(root, 50);
    cout << "After deleting 50: ";
    inorder(root);
    cout << endl;
    
    return 0;
}
