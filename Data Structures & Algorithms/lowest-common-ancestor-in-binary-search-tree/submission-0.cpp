/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* cur = root;

        while (cur) {
            if (p->val > cur->val && q->val > cur->val) {
                cur = cur->right;
            } else if (p->val < cur->val && q->val < cur->val) {
                cur = cur->left;
            } else {
                return cur;
            }
        }
        return nullptr;
    }
};