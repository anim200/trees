#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

vector<int> iterativePreorder(TreeNode* root) {
    vector<int> result;
    
    if (root == NULL) {
        return result;
    }
    
    stack<TreeNode*> st;
    st.push(root);
    
    while (!st.empty()) {
        TreeNode* node = st.top();
        st.pop();
        
        // Process the node (preorder: root first)
        result.push_back(node->data);
        
        // Push right child first so left child is processed first
        if (node->right != NULL) {
            st.push(node->right);
        }
        
        if (node->left != NULL) {
            st.push(node->left);
        }
    }
    
    return result;
}

// Helper function to create a sample tree
TreeNode* createSampleTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    
    return root;
}

int main() {
    TreeNode* root = createSampleTree();
    
    vector<int> preorderResult = iterativePreorder(root);
    
    cout << "Iterative Preorder Traversal: ";
    for (int val : preorderResult) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}
