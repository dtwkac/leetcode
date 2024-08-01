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
    bool isValidBST(TreeNode* root) {
        bool flag = true;
        long long prev = LONG_LONG_MIN;
        function<void(TreeNode*)> dfs = [&dfs, &flag,
                                         &prev](TreeNode* root) -> void {
            if (!root) {
                return;
            }
            dfs(root->left);
            if (root->val <= prev) {
                flag = false;
                return;
            }
            prev = root->val;
            dfs(root->right);
        };
        dfs(root);
        return flag;
    }
};
