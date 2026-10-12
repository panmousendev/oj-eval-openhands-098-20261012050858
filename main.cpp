#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* insert(TreeNode* root, int val) {
    if (root == nullptr) {
        return new TreeNode(val);
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

int cnt = 0;
int ans = -1;

void kthLargest(TreeNode* root, int k) {
    if (root == nullptr) return;
    
    kthLargest(root->right, k);
    
    cnt++;
    if (cnt == k) {
        ans = root->val;
        return;
    }
    
    kthLargest(root->left, k);
}

int main() {
    int values[8];
    for (int i = 0; i < 8; i++) {
        cin >> values[i];
    }
    
    TreeNode* root = nullptr;
    for (int i = 0; i < 7; i++) {
        root = insert(root, values[i]);
    }
    
    int k = values[7];
    
    cnt = 0;
    ans = -1;
    kthLargest(root, k);
    
    cout << ans << endl;
    
    return 0;
}