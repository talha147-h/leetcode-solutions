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
int ans=0;
    void solve(TreeNode* node,long long targetSum){
        if(node==nullptr)return;
        if(targetSum==0)ans++;
        if(node->left)
        solve(node->left,targetSum-node->left->val);
        if(node->right)
        solve(node->right,targetSum-node->right->val);
    }
    void dfs(TreeNode* root, long long targetSum){
        if(root==nullptr) return;
        solve(root,targetSum-root->val);
        if(root->left)
        dfs(root->left,targetSum);
        if(root->right){
        dfs(root->right, targetSum);
        }
    }
    int pathSum(TreeNode* root, int targetSum) {
         dfs(root,targetSum);
         return ans;
    }
};