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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q; // node,idx
        q.push({root, 0});
        int ans = INT_MIN;

int startidx=0;
int lastidx=0;
int index;
        while (!q.empty()) {
            int sz = q.size();
            int k=sz;
            startidx=q.front().second;
            while (sz--) {
                auto [node, idx] = q.front();
                index=idx-startidx;
                q.pop();
                if(sz==0)
                {
                lastidx=index;
                ans=max(ans,index);
                }
                if (node->left)
                    q.push({node->left, (long long)2 * index});
                if (node->right)
                    q.push({node->right, (long long)2 * index + 1});
            }
        }
        return ans+1;
    }
};