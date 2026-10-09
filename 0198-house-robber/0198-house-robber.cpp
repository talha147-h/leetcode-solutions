class Solution {
public:
   int solve(int i,vector<int> nums,vector<int> &dp){
    if(i>=nums.size())return 0;
    if(dp[i]!=-1)return dp[i];
    int s1=nums[i]+solve(i+2,nums,dp);
    int s2=solve(i+1,nums,dp);
    return dp[i]=max(s1,s2);
   }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        return solve(0,nums,dp);
    }
};