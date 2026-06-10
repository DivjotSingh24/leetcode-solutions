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
    int maxDepthSum(TreeNode* root, int& maxPath){
        if(root == nullptr) return 0;
        int leftSum = max(0, maxDepthSum(root->left, maxPath));
        int rightSum = max(0, maxDepthSum(root->right, maxPath));
        maxPath = max(maxPath, (leftSum + rightSum + root->val));
        return max(leftSum, rightSum) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        int maxPath = INT_MIN;
        maxDepthSum(root, maxPath);
        return maxPath;
    }
};