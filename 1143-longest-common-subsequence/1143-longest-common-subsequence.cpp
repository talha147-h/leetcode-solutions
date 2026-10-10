class Solution {
public:
    int solve(int i,int j,string &text1,string &text2,vector<vector<int>> &dp){
        int n=text1.size();
        int m=text2.size();
        if(i>=n || j>=m)return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int len1=0;
        if(text1[i]==text2[j])
        len1=1+solve(i+1,j+1,text1,text2,dp);
        int len2=solve(i+1,j,text1,text2,dp);
        int len3=solve(i,j+1,text1,text2,dp);
        int max1=max(len1,len2);
        return dp[i][j]=max(max1,len3);
    
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,-1));
        return solve(0,0,text1,text2,dp);
    }
};