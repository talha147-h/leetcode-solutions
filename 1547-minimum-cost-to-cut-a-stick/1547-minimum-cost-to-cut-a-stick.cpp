
class Solution {
public:
    int solve(int i, int j, vector<int>& cuts,
              vector<vector<int>>& dp) {
        if (i > j) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int mini = INT_MAX;

        for (int k = i; k <= j; k++) {
            int cost = cuts[j + 1] - cuts[i - 1]
                     + solve(i, k - 1, cuts, dp)
                     + solve(k + 1, j, cuts, dp);

            mini = min(mini, cost);
        }

        return dp[i][j] = mini;
    }

    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());

        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);

        int c = cuts.size() - 2;

        vector<vector<int>> dp(c + 2, vector<int>(c + 2, -1));

        return solve(1, c, cuts, dp);
    }
};
