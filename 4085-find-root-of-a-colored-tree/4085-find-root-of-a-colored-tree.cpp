class Solution {
public:
    int findColoredRoot(vector<vector<int>>& edges, string colors) {
        int n=colors.size();
        vector<int> color(n);
        for(int i=0;i<n;i++){
            if(colors[i]=='R')color[i]=0;
            else if(colors[i]=='B')color[i]=1;
            else color[i]=2;
        }
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        vector<int> outdegree(n,0);
        for(int i=0;i<edges.size();i++){
           int u=edges[i][0];
           int v=edges[i][1];
           if(((color[v]-color[u])+3)%3==1)
           {
            adj[u].push_back(v);
           indegree[v]++;
           outdegree[u]++;
           }
           else if(((color[u]-color[v])+3)%3==1)
           {
            adj[v].push_back(u);
            indegree[u]++;
            outdegree[v]++;
           }
           else return -1;
        }
        for(int i=0;i<n;i++){
            if(outdegree[i]>2)return -1;
        }
        int node=-1;
        int cnt=0;
        
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                cnt++;
                node=i;
            }
        }
        return cnt==1?node:-1;
    }
};