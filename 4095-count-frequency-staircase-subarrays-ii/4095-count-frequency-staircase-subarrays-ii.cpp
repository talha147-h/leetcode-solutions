class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int n = nums.size();
        int K = 0;
        while ((long long)(K + 1) * (K + 2) / 2 <= n) K++;   // max possible distinct count

        vector<int> cnt(100001, 0), rk(100001, 0);
        int ans = 0;

        for (int l = 0; l < n; l++) {
            int k = 0, sat = 0, r = l;
            for (; r < n; r++) {
                int v = nums[r];
                if (cnt[v] == 0) {
                    if (k == K) break;           // too many distinct values
                    rk[v] = ++k;
                    cnt[v] = 1;
                    if (rk[v] == 1) sat++;       // count 1 matches rank 1
                } else {
                    int i = rk[v];
                    if (cnt[v] == i) sat--;
                    cnt[v]++;
                    if (cnt[v] > i) break;       // overshoot, no longer subarray works
                    if (cnt[v] == i) sat++;
                }
                if (sat == k) ans++;
            }
            // reset only the values touched in [l, r]
            for (int j = l; j <= min(r, n - 1); j++) cnt[nums[j]] = 0;
        }
        return ans;
    }
};