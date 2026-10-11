
class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& heights,
             vector<vector<int>>& vis) {

        int n = heights.size();
        int m = heights[0].size();

        vis[i][j] = 1;

        int delrow[] = {1, -1, 0, 0};
        int delcol[] = {0, 0, 1, -1};

        for (int k = 0; k < 4; k++) {
            int newrow = i + delrow[k];
            int newcol = j + delcol[k];

            if (newrow >= 0 && newrow < n &&
                newcol >= 0 && newcol < m &&
                !vis[newrow][newcol] &&
                heights[newrow][newcol] >= heights[i][j]) {

                dfs(newrow, newcol, heights, vis);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> paci(n, vector<int>(m, 0));
        vector<vector<int>> atla(n, vector<int>(m, 0));

        // Pacific: top row and left column
        for (int j = 0; j < m; j++)
            dfs(0, j, heights, paci);

        for (int i = 0; i < n; i++)
            dfs(i, 0, heights, paci);

        // Atlantic: bottom row and right column
        for (int j = 0; j < m; j++)
            dfs(n - 1, j, heights, atla);

        for (int i = 0; i < n; i++)
            dfs(i, m - 1, heights, atla);

        // Find cells that can reach both oceans
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (paci[i][j] && atla[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};
