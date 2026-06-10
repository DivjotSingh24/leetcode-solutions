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
    void preOrder(TreeNode* root, int lvl, int& max_lvl){
        if(!root) return;
        max_lvl = max(max_lvl, lvl+1);
        preOrder(root->left, lvl+1, max_lvl);
        preOrder(root->right, lvl+1, max_lvl);
        return;
    }
    bool isBalanced(TreeNode* root) {
        if(root==nullptr) return true;
        int left_height= 0;
        int right_height = 0;
        if(!isBalanced(root->right)) return false;
        if(!isBalanced(root->left)) return false;
        preOrder(root->left, 0, left_height);
        preOrder(root->right, 0, right_height);
        if(abs(left_height - right_height) > 1){
            return false;
        }
        return true;
    }
};