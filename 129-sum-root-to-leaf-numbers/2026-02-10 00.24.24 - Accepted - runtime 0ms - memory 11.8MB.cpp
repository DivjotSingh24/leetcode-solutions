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
    void solve(TreeNode * root, int &sum , int &temp){
        if(!root) return;
        temp = temp*10 + root->val;
        if(root && !root->left && !root->right){
            sum+=temp;
        }
        else{
            solve(root->left,sum,temp);
            solve(root->right,sum,temp);
        }
        temp -= root->val;
        temp/=10;
    }
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        int sum = 0;
        int temp = 0;
        solve(root,sum,temp);
        return sum;
    }
};