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

int nodeCount = 0;
int result = -1;

void reverseInorder(TreeNode* root, int k) {
    if (root == nullptr || nodeCount >= k) {
        return;
    }
    
    reverseInorder(root->right, k);
    
    nodeCount++;
    if (nodeCount == k) {
        result = root->val;
        return;
    }
    
    reverseInorder(root->left, k);
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
    
    nodeCount = 0;
    result = -1;
    reverseInorder(root, k);
    
    cout << result << endl;
    
    return 0;
}