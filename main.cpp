#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (root == nullptr) {
        return new TreeNode(val);
    }
    if (val < root->val) {
        root->left = insertIntoBST(root->left, val);
    } else {
        root->right = insertIntoBST(root->right, val);
    }
    return root;
}

vector<int> inorderValues;

void inorderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    inorderTraversal(root->left);
    inorderValues.push_back(root->val);
    inorderTraversal(root->right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<int> values(8);
    for (int i = 0; i < 8; i++) {
        cin >> values[i];
    }
    
    TreeNode* root = nullptr;
    
    for (int i = 0; i < 7; i++) {
        root = insertIntoBST(root, values[i]);
    }
    
    int k = values[7];
    
    inorderValues.clear();
    inorderTraversal(root);
    
    if (k >= 1 && k <= inorderValues.size()) {
        cout << inorderValues[inorderValues.size() - k] << endl;
    }
    
    return 0;
}