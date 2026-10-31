class Solution {
public:
   //dir=0 for right
   //dir=1 for down
   int mod=1e9+7;
    int dfs(int i,int j, vector<vector<int>>& grid,int dir,vector<vector<vector<int>>>&dp){
        int n=grid.size();
        int m=grid[0].size();
        if(i==n-1  && j==m-1) return 1;
        if(i>=n || j>=m) return 0;
        if(dp[i][j][dir]!=-1)return dp[i][j][dir]%mod;
        if(grid[i][j]==1){
            if(dir==1){
                dp[i][j][dir]=dfs(i,j+1,grid,0,dp); 
            }
            else{
                dp[i][j][dir]=dfs(i+1,j,grid,1,dp);
            }
        }
        else{
        dp[i][j][dir]=(dfs(i+1,j,grid,1,dp)+dfs(i,j+1,grid,0,dp));
        }
        return dp[i][j][dir]%mod;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int dir=0;
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(2,-1)));
        return dfs(0,0,grid,dir,dp); 
    }
};