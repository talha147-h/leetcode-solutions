class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();

        if (n == 0) return 0;

        vector<int> dp(n, 1);
        vector<int> cnt(n, 1);

        int maxi = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {

                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];
                    }
                    else if (dp[j] + 1 == dp[i]) {
                        cnt[i] += cnt[j];
                    }
                }
            }

            maxi = max(maxi, dp[i]);
        }

        int result = 0;

        for (int i = 0; i < n; i++) {
            if (dp[i] == maxi) {
                result += cnt[i];
            }
        }

        return result;
    }
};