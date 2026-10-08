class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2)q.push({i,j});
            }
        }
        vector<vector<int>> visited(n,vector<int> (m,0));
        int minutes=0;
        int newcount=0;
        while(!q.empty()){
            int sz=q.size();
            minutes++;
            while(sz--){
               int delrow[]={1,-1,0,0};
               int delcol[]={0,0,1,-1}; 
               auto[i,j]=q.front();
               q.pop();
               for(int k=0;k<4;k++){
                int newrow=i+delrow[k];
                int newcol=j+delcol[k];
                if(newrow>=0 && newcol>=0 && newrow<n && newcol<m && grid[newrow][newcol]==1)
               { q.push({newrow,newcol});grid[newrow][newcol]=2;}
               }
            }
        }
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1)return -1;
        }
     }
        return max(0,minutes-1);
    }
};