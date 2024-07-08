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
    int getHeight(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int left_height = getHeight(root->left);
        int right_height = getHeight(root->right);
        if (left_height == -1 || right_height == -1 ||
            abs(left_height - right_height) > 1) {
            return -1;
        } else {
            return 1 + max(left_height, right_height);
        }
    }

    bool isBalanced(TreeNode* root) { return getHeight(root) > -1; }
};
