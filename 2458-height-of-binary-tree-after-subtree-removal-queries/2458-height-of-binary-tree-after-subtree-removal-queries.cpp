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
    vector<int> depth, height;
    vector<int> mx1, mx2;

    int dfs(TreeNode* root, int d) {
        if (!root) return -1;

        depth[root->val] = d;

        int left = dfs(root->left, d + 1);
        int right = dfs(root->right, d + 1);

        height[root->val] = 1 + max(left, right);

        int h = height[root->val];

        if (h > mx1[d]) {
            mx2[d] = mx1[d];
            mx1[d] = h;
        }
        else if (h > mx2[d]) {
            mx2[d] = h;
        }

        return h;
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        int n = 100001;

        depth.assign(n, 0);
        height.assign(n, 0);
        mx1.assign(n, -1);
        mx2.assign(n, -1);

        dfs(root, 0);

        vector<int> ans;

        for (int q : queries) {
            int d = depth[q];
            int h = height[q];

            if (h == mx1[d]) {
                if (mx2[d] == -1)
                    ans.push_back(d - 1);
                else
                    ans.push_back(d + mx2[d]);
            }
            else {
                ans.push_back(d + mx1[d]);
            }
        }

        return ans;
    }
};