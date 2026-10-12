#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildBSTFromLevelOrder(const vector<int>& values) {
    if (values.empty()) return nullptr;
    
    TreeNode* root = new TreeNode(values[0]);
    queue<TreeNode*> q;
    q.push(root);
    
    int index = 1;
    while (!q.empty() && index < values.size()) {
        TreeNode* current = q.front();
        q.pop();
        
        if (index < values.size()) {
            if (values[index] < current->val) {
                current->left = new TreeNode(values[index]);
                q.push(current->left);
            } else {
                current->right = new TreeNode(values[index]);
                q.push(current->right);
            }
            index++;
        }
        
        if (index < values.size()) {
            if (values[index] < current->val) {
                if (current->left == nullptr) {
                    current->left = new TreeNode(values[index]);
                    q.push(current->left);
                } else {
                    TreeNode* temp = current->left;
                    while (temp->right != nullptr) {
                        temp = temp->right;
                    }
                    temp->right = new TreeNode(values[index]);
                    q.push(temp->right);
                }
            } else {
                if (current->right == nullptr) {
                    current->right = new TreeNode(values[index]);
                    q.push(current->right);
                } else {
                    TreeNode* temp = current->right;
                    while (temp->left != nullptr) {
                        temp = temp->left;
                    }
                    temp->left = new TreeNode(values[index]);
                    q.push(temp->left);
                }
            }
            index++;
        }
    }
    
    return root;
}

int count = 0;
int result = -1;

void reverseInorder(TreeNode* root, int k) {
    if (root == nullptr || count >= k) {
        return;
    }
    
    reverseInorder(root->right, k);
    
    count++;
    if (count == k) {
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
    
    vector<int> bstValues(values.begin(), values.begin() + 7);
    TreeNode* root = buildBSTFromLevelOrder(bstValues);
    
    int k = values[7];
    
    count = 0;
    result = -1;
    reverseInorder(root, k);
    
    cout << result << endl;
    
    return 0;
}