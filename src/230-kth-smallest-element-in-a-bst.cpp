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
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        function<void(TreeNode*)> dfs = [&dfs, &ans,
                                         &k](TreeNode* root) -> void {
            if (!root) {
                return;
            }
            dfs(root->left);
            --k;
            if (k == 0) {
                ans = root->val;
                return;
            }
            dfs(root->right);
        };
        dfs(root);
        return ans;
    }
};
