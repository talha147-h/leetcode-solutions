class Solution{
public:
int solve(int i,int j,vector<vector<int>>&mat,vector<vector<int>>&dp){
if(i>=mat.size()||j>=mat[0].size())return 0;
if(dp[i][j]!=-1)return dp[i][j];
int right=solve(i,j+1,mat,dp);
int down=solve(i+1,j,mat,dp);
int diag=solve(i+1,j+1,mat,dp);
if(mat[i][j]==0)return dp[i][j]=0;
return dp[i][j]=1+min({right,down,diag});
}
int countSquares(vector<vector<int>>&matrix){
int n=matrix.size(),m=matrix[0].size(),ans=0;
vector<vector<int>>dp(n,vector<int>(m,-1));
for(int i=0;i<n;i++)
for(int j=0;j<m;j++)
ans+=solve(i,j,matrix,dp);
return ans;
}
};