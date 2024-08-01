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
    int sumNumbers(TreeNode* root) {
        int sum = 0, num = 0;
        function<void(TreeNode*)> dfs = [&dfs, &sum,
                                         &num](TreeNode* root) -> void {
            if (!root) {
                return;
            }
            num = num * 10 + root->val;
            if (!root->left && !root->right) {
                sum += num;
            }
            dfs(root->left);
            dfs(root->right);
            num /= 10;
        };
        dfs(root);
        return sum;
    }
};
