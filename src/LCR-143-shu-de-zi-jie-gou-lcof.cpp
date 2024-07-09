/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isExactSubStructure(TreeNode* p, TreeNode* q) {
        if (!q) {
            return true;
        }
        if (!p) {
            return false;
        }
        return p->val == q->val && isExactSubStructure(p->left, q->left) &&
               isExactSubStructure(p->right, q->right);
    }

    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (!A || !B) {
            return false;
        }
        return isExactSubStructure(A, B) || isSubStructure(A->left, B) ||
               isSubStructure(A->right, B);
    }
};
