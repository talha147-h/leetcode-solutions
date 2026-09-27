
class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {

        map<pair<int,int>, int> mp;

        int ans = 0;

        // Count existing equal adjacent pairs
        for (int i = 0; i + 1 < nums.size(); i++) {
            if (nums[i] == nums[i + 1]) {
                ans++;
            }
            else {
                mp[{nums[i], nums[i + 1]}]++;
                mp[{nums[i + 1], nums[i]}]++;
            }
        }

        int best = 0;

        for (auto it = mp.begin(); it != mp.end(); it++) {
            best = max(best, it->second);
        }

        return ans + best;
    }
};