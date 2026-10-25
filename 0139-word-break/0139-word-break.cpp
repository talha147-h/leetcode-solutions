class Solution {
public:
    bool solve(int i,string s,  set<string> &words,vector<int>&dp){
        int n=s.size();
        if(i==n) return true;
        if(dp[i]!=-1)return dp[i];
        bool ans=false;
        for(int j=i;j<n;j++){
            if(words.find(s.substr(i,j-i+1))!=words.end()){
                ans=solve(j+1,s,words,dp);
                if(ans)break;
            }
        }
        if(ans)dp[i]=1;
        else dp[i]=0;
        return ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<int>dp(n+1,-1);
        set<string> words(wordDict.begin(),wordDict.end());
        return solve(0,s,words,dp);
    }
};