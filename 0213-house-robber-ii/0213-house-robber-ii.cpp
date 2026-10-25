class Solution {
public:
int picknonpick(int index,vector<int>& nums,vector<int>& dp,int c)
    {
     if(index==0&& c==0)return nums[0];
     if(index==0 && c==1) return 0;
     if(index<0)return 0;
     if(dp[index]!=-1) return dp[index];
     int pick =nums[index]+picknonpick(index-2,nums,dp,c);
     int nonpick=0+picknonpick(index-1,nums,dp,c);
     return dp[index]=max(pick,nonpick);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);
        vector<int> dp(nums.size(),-1);
        int index=nums.size()-1;
        int ans=picknonpick(index,nums,dp,1);
        vector<int> dp1(nums.size(),-1);
        int ans2=picknonpick(index-1,nums,dp1,0);
        return max(ans,ans2);
    }
};