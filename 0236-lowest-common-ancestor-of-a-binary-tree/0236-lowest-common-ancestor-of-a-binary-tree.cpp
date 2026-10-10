/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
      TreeNode* solve(TreeNode* node, TreeNode* p, TreeNode* q) {
        if(node==NULL )return NULL;
        if(node==p)return p;
        if(node==q)return q;
        TreeNode* find1=solve(node->left,p,q);
        TreeNode* find2=solve(node->right,p,q);
        if(find1 && find2)return node;
        if(find1)return find1;
        if(find2) return find2;
        return NULL;
      }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root,p,q);
    }
};