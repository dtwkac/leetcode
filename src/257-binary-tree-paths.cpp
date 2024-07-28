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
    vector<string> binaryTreePaths(TreeNode* root) {
        string path;
        vector<string> paths;
        function<void(TreeNode*)> dfs = [&dfs, &path,
                                         &paths](TreeNode* root) -> void {
            if (!root) {
                return;
            }
            path += to_string(root->val) + "->";
            if (!root->left && !root->right) {
                paths.push_back(path.substr(0, path.size() - 2));
            }
            dfs(root->left);
            dfs(root->right);
            path.erase(path.size() - to_string(root->val).size() - 2);
        };
        dfs(root);
        return paths;
    }
};
