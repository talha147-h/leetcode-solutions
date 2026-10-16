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
int count=0;
    void dfs(TreeNode* node, int target,unordered_map<long long,int> &prefix,long long currsum){
        if(!node)return;
        currsum+=node->val;
         if(prefix.find(currsum-target)!=prefix.end()){
            count+=prefix[currsum-target];
        }
        prefix[currsum]++;
        dfs(node->left,target,prefix,currsum);
        dfs(node->right,target,prefix,currsum);
        prefix[currsum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long,int> prefix;
        prefix[0]=1;
        dfs(root,targetSum,prefix,0);
        return count;
    }
};