class Solution {
public:
    int solve(int i,vector<int>& nums,int prevgreater, vector<vector<int>> &dp){
        int n=nums.size();
     if(i==n)return 0;
     if(prevgreater!=-1 && dp[i][prevgreater+1]!=-1)return dp[i][prevgreater+1];
     int take=0;
     if(prevgreater == -1 || nums[i] > nums[prevgreater]){
         take=1+solve(i+1,nums,i,dp);
     }
      int skip=solve(i+1,nums,prevgreater,dp);
      return dp[i][prevgreater+1]= max(skip,take);
    }
    int lengthOfLIS(vector<int>& nums) {
        int x=*max_element(nums.begin(),nums.end());
        vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        return solve(0,nums,-1,dp);
    }
};