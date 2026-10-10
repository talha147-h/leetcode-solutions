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
    vector <TreeNode*> inorder;
public:
    void dfs(TreeNode* root)
    {
        if(!root)return;
        dfs(root->left);
        inorder.push_back(root);
        dfs(root->right);
    }
    bool isValidBST(TreeNode* root) {
        dfs(root);
        bool validity=true;
        for(int i=0;i<inorder.size()-1;i++)
        {
            if(inorder[i]->val>=inorder[i+1]->val)
            validity=false;
        }
        return validity;
    }
};