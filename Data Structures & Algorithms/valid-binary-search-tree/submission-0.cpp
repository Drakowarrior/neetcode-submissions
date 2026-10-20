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
    bool isValidBST(TreeNode* root) {
        if (!root) {
            return true;
        }

        queue<tuple<TreeNode*, long, long>> queue;
        queue.push(make_tuple(root, LONG_MIN, LONG_MAX));

        while (!queue.empty()) {
            auto [node, left, right] = queue.front();
            queue.pop();

            if (!(left < node->val && node->val < right)) {
                return false;
            }
            if (node->left) {
                queue.push(make_tuple(node->left, left, node->val));
            }
            if (node->right) {
                queue.push(make_tuple(node->right, node->val, right));
            }
        }

        return true;
    }
};