#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildBSTFromLevelOrder(const vector<int>& values) {
    if (values.empty()) return nullptr;
    
    vector<TreeNode*> nodes;
    for (int val : values) {
        nodes.push_back(new TreeNode(val));
    }
    
    for (int i = 0; i < nodes.size(); i++) {
        int leftIdx = 2 * i + 1;
        int rightIdx = 2 * i + 2;
        
        if (leftIdx < nodes.size()) {
            nodes[i]->left = nodes[leftIdx];
        }
        if (rightIdx < nodes.size()) {
            nodes[i]->right = nodes[rightIdx];
        }
    }
    
    return nodes[0];
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
    
    vector<int> bstValues(values.begin(), values.begin() + 7);
    TreeNode* root = buildBSTFromLevelOrder(bstValues);
    
    int k = values[7];
    
    nodeCount = 0;
    result = -1;
    reverseInorder(root, k);
    
    cout << result << endl;
    
    return 0;
}