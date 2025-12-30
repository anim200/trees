#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to find the floor of a value in BST
// Floor is the largest value less than or equal to x
int findFloor(Node* root, int x) {
    int res = -1;
    
    while (root) {
        if (root->data == x) {
            return root->data;
        }
        
        if (root->data < x) {
            res = root->data;  // This could be the floor
            root = root->right;  // Check if there's a larger value in right subtree
        } else {
            root = root->left;  // x is smaller, so we need to go left
        }
    }
    
    return res;
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

// Driver code
int main() {
    Node* root = nullptr;
    
    // Insert values: 15, 10, 20, 8, 12, 17, 25
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 8);
    root = insert(root, 12);
    root = insert(root, 17);
    root = insert(root, 25);
    
    int x = 13;
    int result = findFloor(root, x);
    
    cout << "Floor of " << x << " is: ";
    if (result == -1) {
        cout << "No floor found" << endl;
    } else {
        cout << result << endl;
    }
    
    return 0;
}
