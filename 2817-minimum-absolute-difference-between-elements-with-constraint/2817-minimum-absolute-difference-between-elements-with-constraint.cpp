class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int n=nums.size();
        set<int> s;
        int ans=INT_MAX;
        for(int j=n-1;j>=x;j--){
            int i=j-x;
            s.insert(nums[j]);
            auto it=s.upper_bound(nums[i]);
            if(it!=s.end())
            ans=min(ans,abs(nums[i]-*it));
 
            if(it!=s.begin())
            ans=min(ans,abs(nums[i]-*prev(it)));
        }
        return ans;
    }
};