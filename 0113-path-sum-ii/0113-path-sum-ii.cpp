/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> dfs(TreeNode* root, int targetSum ,vector<vector<int>>&ans,vector<int>&v) {
        if (root == nullptr)
            return ans;
        if (root->left == nullptr && root->right == nullptr) {
            targetSum -= root->val;
            v.push_back(root->val);
            if (targetSum == 0) {
                ans.push_back(v);
            }
            v.pop_back();
        }
        if (root->left) {
            v.push_back(root->val);
            dfs(root->left, targetSum - root->val, ans, v);
            v.pop_back();
        }

        if (root->right) {
            v.push_back(root->val);
            dfs(root->right, targetSum - root->val, ans, v);
            v.pop_back();
        }
        return ans;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> v;
        return dfs(root, targetSum, ans, v);
    }
};