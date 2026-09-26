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
    TreeNode* lcafn(TreeNode* node, TreeNode* p, TreeNode* q){
    if(!node)return NULL;
    if(node==p)return node;
    if(node==q)return node;
    TreeNode* leftfound=lcafn(node->left,p,q);
    TreeNode* rightfound=lcafn(node->right,p,q);
    if(leftfound && rightfound)return node;
    if(leftfound)return leftfound;
    if(rightfound)return rightfound;
    return nullptr;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lcafn(root,p,q);
    }
};