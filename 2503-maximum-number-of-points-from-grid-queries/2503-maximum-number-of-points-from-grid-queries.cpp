class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int x=queries.size();
        vector<int> ans(x);
        vector<pair<int,int>> sorted(x);
        for(int i=0;i<x;i++){
            sorted[i]={queries[i],i};
        }
        sort(sorted.begin(),sorted.end());
        int points=0;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        priority_queue<pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
                greater<pair<int,pair<int,int>>>>  pq;
        pq.push({grid[0][0],{0,0}});
        vis[0][0]=1;
        int i=0;
        int dr[]={1,-1,0,0};
        int dc[]={0,0,1,-1};
        while(!pq.empty() && i<x)
        {
            int val=pq.top().first;
            auto [r,c]=pq.top().second;
            pq.pop();
            while(i<x && val>=sorted[i].first){
                ans[sorted[i].second]=points;
                i++;
           }
           points++;
        for(int k=0;k<4;k++){
            int nr=r+dr[k];
            int nc=c+dc[k];
            if(nr>=0 && nr<m && nc>=0 && nc<n && vis[nr][nc]==0 )
            {
                vis[nr][nc]=1;
                pq.push({grid[nr][nc],{nr,nc}});
            }
        }
        }
        while(i!=x){
            ans[sorted[i].second]=points;
            i++;
        }
        return ans;
    }
};