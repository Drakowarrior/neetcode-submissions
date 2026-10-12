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
    int diameterOfBinaryTree(TreeNode* root) {
        unordered_map<TreeNode*, pair<int, int>> mp;
        mp[nullptr] = {0, 0};
        stack<TreeNode*> stack;
        stack.push(root);

        while (!stack.empty()) {
            TreeNode* node = stack.top();

            if (node->left && mp.find(node->left) == mp.end()) {
                stack.push(node->left);
            } else if (node->right && mp.find(node->right) == mp.end()) {
                stack.push(node->right);
            } else {
                node = stack.top();
                stack.pop();

                auto[leftHeight, leftDiameter] = mp[node->left];
                auto[rightHeight, rightDiameter] = mp[node->right];

                int height = 1 + std::max(leftHeight, rightHeight);
                int diameter = max(leftHeight + rightHeight,
                               max(leftDiameter, rightDiameter));

                mp[node] = {height, diameter};
            }
        }
        return mp[root].second;
    }
};