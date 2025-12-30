#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

void levelOrder(Node* root) {
    if (root == nullptr) return;
    
    vector<vector<int>> result;
    queue<Node*> q;
    q.push(root);
    
    while (!q.empty()) {
        int levelSize = q.size();
        vector<int> level;
        
        for (int i = 0; i < levelSize; i++) {
            Node* curr = q.front();
            q.pop();
            
            level.push_back(curr->data);
            
            if (curr->left != nullptr)
                q.push(curr->left);
            if (curr->right != nullptr)
                q.push(curr->right);
        }
        result.push_back(level);
    }
    
    // Print result
    for (auto level : result) {
        for (int val : level)
            cout << val << " ";
        cout << "\n";
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    
    levelOrder(root);
    
    return 0;
}
