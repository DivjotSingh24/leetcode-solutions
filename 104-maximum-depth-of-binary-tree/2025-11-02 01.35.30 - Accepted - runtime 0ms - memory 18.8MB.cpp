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
    int max_lvl = 0;

    void preOrder(TreeNode* root, int lvl) {
        if (!root) return;
        max_lvl = max(max_lvl, lvl + 1);
        preOrder(root->left, lvl + 1);
        preOrder(root->right, lvl + 1);
    }

    int maxDepth(TreeNode* root) {
        preOrder(root, 0);
        return max_lvl;
    }
};
