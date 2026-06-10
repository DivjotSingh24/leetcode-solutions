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
using ll = long long;
ll ans = 0;
int mod = 1e9+7;
ll find(TreeNode *root){
    if(!root) return 0;
    else return root->val + find(root->left)+find(root->right);
}
int dfs(TreeNode *root , ll sum){
    if(!root) return 0;
    ll left = dfs(root->left,sum);
    ll right = dfs(root->right,sum);
    ll curr = root->val+left+right;
    ans=max(ans,(sum-curr)*curr);
    return curr;
}
    int maxProduct(TreeNode* root) {
        ll sum = find(root);
        dfs(root,sum);
        return ans%mod;
    }
};