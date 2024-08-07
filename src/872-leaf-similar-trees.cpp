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
    void preorderTraversal(TreeNode* root, vector<int>& v) {
        if (!root) {
            return;
        }
        if (!root->left && !root->right) {
            v.push_back(root->val);
        }
        preorderTraversal(root->left, v);
        preorderTraversal(root->right, v);
    }

    vector<int> leafVector(TreeNode* root) {
        vector<int> v;
        preorderTraversal(root, v);
        return v;
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        return leafVector(root1) == leafVector(root2);
    }
};
