class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
      queue<pair<int,int>> q;
      int n=grid.size();
      int m=grid[0].size();
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2)
            q.push({i,j});
        }
      }  
      int minutes=0;
      int dr[]={1,-1,0,0};
      int dc[]={0,0,1,-1};
      while(!q.empty()){
        int sz=q.size();
        minutes++;
        while(sz--){
        auto[r,c]=q.front();
        q.pop();
        for(int k=0;k<4;k++){
            int nr=r+dr[k];
            int nc=c+dc[k];
            if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]==1)
            {
                grid[nr][nc]=2;
                q.push({nr,nc});
            }
        }
        }
      }
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
        if(grid[i][j]==1)return -1;
      }
      return max(0,minutes-1);
    }
};