class Solution {
public:
    int func(int len, vector<int>& dp, int low, int high, int zero, int one) {
        const int MOD=1000000007;
        if(len>high)return 0;
        if(dp[len]!=-1)return dp[len];

        long long ans=0;

        if(len>=low)ans=1;
       ans+= func(len+zero,dp,low,high,zero,one)+func(len+one,dp,low,high,zero,one);
        return dp[len]=ans%MOD;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1,-1);
        return func(0,dp,low,high,zero,one);
    }
};