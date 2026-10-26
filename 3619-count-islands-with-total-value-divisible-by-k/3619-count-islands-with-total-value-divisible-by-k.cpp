class Solution {
public:
    long long dfs(int i,int j,vector<vector<int>>&vis,vector<vector<int>> & grid){
        int n=grid.size();
        int m=grid[0].size();
        vis[i][j]=1;
        int dr[]={1,-1,0,0};
        int dc[]={0,0,1,-1};
        long  long  sum=grid[i][j];
        for(int k=0;k<4;k++){
            int nr=i+dr[k];
            int nc=j+dc[k];
            if(nr>=0 && nc>=0 && nr<n && nc<m && vis[nr][nc]==0 && grid[nr][nc]!=0){
                sum+=dfs(nr,nc,vis,grid);
            }
        }
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
      int n=grid.size();
      int m=grid[0].size();
      long long sum=0;
      int ans=0;
      vector<vector<int>> vis(n,vector<int>(m,0));
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]==0 && grid[i][j]!=0){
            sum=dfs(i,j,vis,grid);
            if(sum%k==0)ans++;
            }
        }
      }
      return ans;
    }
};