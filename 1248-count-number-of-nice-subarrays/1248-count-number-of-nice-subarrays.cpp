class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
       vector<int> cnt(n+1);
       cnt[0]++;
       int prefix=0;
       int ans=0;
       for(int i=0;i<n;i++){
        prefix+=nums[i]%2;
        cnt[prefix]++;
        if(prefix-k>=0){
            ans+=cnt[prefix-k];
        }
       }
        return ans;
    }
};