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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        function<bool(TreeNode*, TreeNode*)> isSameTree =
            [&isSameTree](TreeNode* p, TreeNode* q) -> bool {
            if (!p && !q) {
                return true;
            }
            if ((p && !q) || (!p && q)) {
                return false;
            }
            return p->val == q->val && isSameTree(p->left, q->left) &&
                   isSameTree(p->right, q->right);
        };
        if (!root) {
            return false;
        }
        return isSameTree(root, subRoot) || isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};
