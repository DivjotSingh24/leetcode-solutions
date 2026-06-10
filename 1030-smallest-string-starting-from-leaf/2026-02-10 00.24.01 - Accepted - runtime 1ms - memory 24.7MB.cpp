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
    void solve(TreeNode * root, vector<string> &ans, string temp){
        if(!root) return;
        temp += char('a' + root->val);
        if(root && !root->left && !root->right){
            reverse(temp.begin(),temp.end());
            ans.push_back(temp);
        }
        else{
            solve(root->left,ans,temp);
            solve(root->right,ans,temp);
        }
        temp.pop_back();
        return;
    }
    string smallestFromLeaf(TreeNode* root) {
        if(!root) return "";
        vector<string> ans;
        string temp = "";
        solve(root,ans,temp);
        sort(ans.begin(),ans.end());
        return ans[0];
    }
};