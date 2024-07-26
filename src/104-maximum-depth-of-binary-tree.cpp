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
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        while (!q.empty()) {
            ++depth;
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* t = q.front();
                if (t->left) {
                    q.push(t->left);
                }
                if (t->right) {
                    q.push(t->right);
                }
                q.pop();
            }
        }
        return depth;
    }
};
