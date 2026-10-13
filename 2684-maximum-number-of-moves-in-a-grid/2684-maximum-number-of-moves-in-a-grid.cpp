
class Solution {
public:
    int calc(int i, int j, vector<vector<int>>& grid,
             vector<vector<int>>& dp) {
        
        int n = grid.size();
        int m = grid[0].size();

        if (j == m - 1)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int updiag = 0, right = 0, downdiag = 0;

        if (i > 0 && grid[i - 1][j + 1] > grid[i][j])
            updiag = 1 + calc(i - 1, j + 1, grid, dp);

        if (grid[i][j + 1] > grid[i][j])
            right = 1 + calc(i, j + 1, grid, dp);

        if (i + 1 < n && grid[i + 1][j + 1] > grid[i][j])
            downdiag = 1 + calc(i + 1, j + 1, grid, dp);

        return dp[i][j] = max({updiag, right, downdiag});
    }

    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        int ans = 0;

        for (int i = 0; i < n; i++)
            ans = max(ans, calc(i, 0, grid, dp));

        return ans;
    }
};
