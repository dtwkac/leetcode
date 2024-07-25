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
    TreeNode* buildTree(const vector<int>& inorder, int inorder_low,
                        int inorder_high, const vector<int>& postorder,
                        int postorder_low, int postorder_high) {
        if (inorder_low > inorder_high) {
            return nullptr;
        }
        int left_size = 0;
        while (inorder[inorder_low + left_size] != postorder[postorder_high]) {
            ++left_size;
        }
        int right_size = inorder_high - inorder_low + 1 - left_size - 1;
        return new TreeNode(
            postorder[postorder_high],
            buildTree(inorder, inorder_low, inorder_low + left_size - 1,
                      postorder, postorder_low, postorder_low + left_size - 1),
            buildTree(inorder, inorder_low + left_size + 1, inorder_high,
                      postorder, postorder_low + left_size,
                      postorder_high - 1));
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, 0, inorder.size() - 1, postorder, 0,
                         postorder.size() - 1);
    }
};
