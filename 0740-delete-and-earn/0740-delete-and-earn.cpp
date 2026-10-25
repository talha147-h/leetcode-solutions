class Solution {
public:
    int solve(int i,vector<int>&points,vector<int>&dp){
        if(i<0)return 0;
        if(dp[i]!=-1)return dp[i];
        int take=points[i]+solve(i-2,points,dp);
        int nottake=solve(i-1,points,dp);
        return dp[i]=max(take,nottake);
    }
    int deleteAndEarn(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        vector<int> points(maxi+1,0);
        for(int x:nums){
            points[x]+=x;
        }
        vector<int> dp(maxi+1,-1);
        return solve(maxi,points,dp);
    }
}; 
