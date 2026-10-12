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
    } else if (val > root->val) {
        root->right = insertIntoBST(root->right, val);
    }
    return root;
}

int countNodes(TreeNode* root) {
    if (root == nullptr) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

TreeNode* findKthLargest(TreeNode* root, int& k) {
    if (root == nullptr) return nullptr;
    
    TreeNode* right = findKthLargest(root->right, k);
    if (right != nullptr) return right;
    
    k--;
    if (k == 0) return root;
    
    return findKthLargest(root->left, k);
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
    
    int totalNodes = countNodes(root);
    if (k >= 1 && k <= totalNodes) {
        TreeNode* result = findKthLargest(root, k);
        if (result != nullptr) {
            cout << result->val << endl;
        }
    }
    
    return 0;
}