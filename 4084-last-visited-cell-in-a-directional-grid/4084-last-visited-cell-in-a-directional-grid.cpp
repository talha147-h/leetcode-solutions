class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int row=0;
        int col=0;
        queue<pair<int,int>> q;
        q.push({0,0});
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        pair<int,int> ans;
        while(!q.empty()){
            auto[i,j]=q.front();
            ans={i,j};
            vis[i][j]=1;
            q.pop();
            char ch=grid[i][j];
            if(ch=='U'&&(i-1>=0 && vis[i-1][j]!=1 ))
            q.push({i-1,j});
            else if(ch=='D'&&( i+1<n && vis[i+1][j]!=1 ))
            q.push({i+1,j});
            else if(ch=='R'&&(  j+1<m && vis[i][j+1]!=1))
            q.push({i,j+1});
            else if(ch=='L'&&(j-1>=0 && vis[i][j-1]!=1))
            q.push({i,j-1});
        }
        vector<int> val;
        val.push_back(ans.first);
        val.push_back(ans.second);
        return val;
    }
};