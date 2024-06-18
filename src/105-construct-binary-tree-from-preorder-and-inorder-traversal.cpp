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
    TreeNode* buildTree(const vector<int>& preorder, int preorder_low,
                        int preorder_high, const vector<int> inorder,
                        int inorder_low, int inorder_high) {
        if (preorder_low > preorder_high) {
            return nullptr;
        }
        if (preorder_low == preorder_high) {
            return new TreeNode(preorder[preorder_low]);
        }
        int left_size = 0;
        while (inorder[inorder_low + left_size] != preorder[preorder_low]) {
            ++left_size;
        }
        return new TreeNode(
            preorder[preorder_low],
            buildTree(preorder, preorder_low + 1, preorder_low + left_size,
                      inorder, inorder_low, inorder_low + left_size - 1),
            buildTree(preorder, preorder_low + 1 + left_size, preorder_high,
                      inorder, inorder_low + left_size + 1, inorder_high));
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0,
                         inorder.size() - 1);
    }
};
