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
    TreeNode* lca(TreeNode* node,TreeNode* node1,TreeNode* node2){
        if(node==NULL)return NULL;
        if(node==node1)return node1;
    if(node==node2)return node2;
    TreeNode* left=lca(node->left,node1,node2);
    TreeNode* right=lca(node->right,node1,node2);
    if(left && right)return node;
    if(left)return left;
    return right;
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
  queue<TreeNode*> q;
  queue<TreeNode*> temp;
  q.push(root);
  while(!q.empty())
  {
    int sz=q.size();
    temp=q;
    while(sz--){
      TreeNode* node=q.front();
      q.pop();
      if(node->left)q.push(node->left);
      if(node->right)q.push(node->right);
    }
  }      
  if(temp.size()==1)
  return temp.front();

  TreeNode* last=temp.front();
  temp.pop();
   while(!temp.empty()){
    last=lca(root,last,temp.front());
    temp.pop();
   }
   return last;
    }
};