/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> v(size);
            for (int i = 0; i < size; ++i) {
                TreeNode* curr = q.front();
                if (curr) {
                    q.push(curr->left);
                    q.push(curr->right);
                }
                v[i] = curr ? curr->val : INT_MIN;
                q.pop();
            }
            for (int i = 0; i < size / 2; ++i) {
                if (v[i] != v[size - 1 - i]) {
                    return false;
                }
            }
        }
        return true;
    }
};
