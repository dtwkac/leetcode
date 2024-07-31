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
    int getMinimumDifference(TreeNode* root) {
        int prev = INT_MIN + 100000, min = INT_MAX;
        function<void(TreeNode*)> dfs = [&dfs, &prev,
                                         &min](TreeNode* root) -> void {
            if (!root) {
                return;
            }
            dfs(root->left);
            int delta = root->val - prev;
            min = delta < min ? delta : min;
            prev = root->val;
            dfs(root->right);
        };
        dfs(root);
        return min;
    }
};
