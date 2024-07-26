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
    int minDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int min = INT_MAX;
        function<void(TreeNode*, int)> dfs = [&dfs, &min](TreeNode* root,
                                                          int depth) -> void {
            if (!root) {
                return;
            }
            ++depth;
            if (!root->left && !root->right) {
                min = depth < min ? depth : min;
                return;
            }
            dfs(root->left, depth);
            dfs(root->right, depth);
        };
        dfs(root, 0);
        return min;
    }
};
