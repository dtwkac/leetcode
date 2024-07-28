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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        vector<vector<int>> paths;
        function<void(TreeNode*, int)> dfs =
            [&dfs, &path, &paths](TreeNode* root, int targetSum) -> void {
            if (!root) {
                return;
            }
            path.push_back(root->val);
            targetSum -= root->val;
            if (!root->left && !root->right && targetSum == 0) {
                paths.push_back(path);
            }
            dfs(root->left, targetSum);
            dfs(root->right, targetSum);
            path.pop_back();
        };
        dfs(root, targetSum);
        return paths;
    }
};
