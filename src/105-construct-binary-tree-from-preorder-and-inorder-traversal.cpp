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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() && inorder.empty()) {
            return nullptr;
        }
        int left_size = 0;
        while (inorder[left_size] != preorder[0]) {
            ++left_size;
        }
        int right_size = preorder.size() - 1 - left_size;
        vector<int> left_preorder, left_inorder;
        for (int i = 0; i < left_size; ++i) {
            left_preorder.push_back(preorder[1 + i]);
            left_inorder.push_back(inorder[i]);
        }
        vector<int> right_preorder, right_inorder;
        for (int i = 0; i < right_size; ++i) {
            right_preorder.push_back(preorder[1 + left_size + i]);
            right_inorder.push_back(inorder[left_size + 1 + i]);
        }
        return new TreeNode(preorder[0], buildTree(left_preorder, left_inorder),
                            buildTree(right_preorder, right_inorder));
    }
};
