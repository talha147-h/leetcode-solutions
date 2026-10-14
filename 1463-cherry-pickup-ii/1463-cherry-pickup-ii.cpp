class Solution {
public:
   int solve(int row,int col1,int col2,vector<vector<int>>&grid,vector<vector<vector<int>>> &dp){
    int n=grid.size();
    int m=grid[0].size();
    if(row==n-1)
    {
         if(col1==col2)return grid[row][col1];
   else return grid[row][col1]+grid[row][col2];
    }
    if(dp[row][col1][col2]!=-1)return dp[row][col1][col2];
   int del[]={-1,0,1};
   int cherries=INT_MIN;
   int steps;
   for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
        if(col1+del[i]>=0 && col1+del[i]<m &&col2+del[j]>=0 && col2+del[j]<m)
        {
            steps=solve(row+1,col1+del[i],col2+del[j],grid,dp);
             cherries=max(cherries,steps);
        }
  
    }
   }
   if(cherries==INT_MIN)return dp[row][col1][col2]=0;
   if(col1==col2)cherries+=grid[row][col1];
   else cherries+=grid[row][col1]+grid[row][col2];
   
   return dp[row][col1][col2]=cherries;
   }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
    int m=grid[0].size();
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
    return solve(0,0,grid[0].size()-1,grid,dp);
    }
};