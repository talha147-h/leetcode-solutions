class Solution {
public:
    bool solve(int i,vector<int> &nums,int totsum,int sum,vector<vector<int>> &dp){
        int n=nums.size();
        if(i==n && sum!=(totsum/2))return false;
        if(sum==(totsum/2))return true;
        if(dp[i][sum]!=-1)return dp[i][sum];
        int take=solve(i+1,nums,totsum,sum+nums[i],dp);
        int nottake=solve(i+1,nums,totsum,sum,dp);
        if(take|| nottake){dp[i][sum]=1;return true;}
         {dp[i][sum]=0;return false;}
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2)return false;
        vector<vector<int>> dp(n,vector<int>(sum,-1));
        return solve(0,nums,sum,0,dp);
    }
};