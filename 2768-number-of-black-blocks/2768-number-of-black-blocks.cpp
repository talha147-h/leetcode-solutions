class Solution {
public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
        map<pair<int,int>,int> mpp;
        for(int i=0;i<coordinates.size();i++){
            int r=coordinates[i][0];
            int c=coordinates[i][1];
            int dr[]={-1,0,-1,0};
            int dc[]={0,-1,-1,0};
            for(int k=0;k<4;k++){
                int nr=r+dr[k];
                int nc=c+dc[k];
                if(nr>=0 && nc>=0 && nr+1<m && nc+1<n){
                    mpp[{nr,nc}]++;
                }
            }
        }
        vector<long long> ans(5,0);
        for(auto it: mpp){
        ans[it.second]++;
        }
        long long total=1LL*(m-1)*(n-1);
        ans[0]=total-(ans[1]+ans[2]+ans[3]+ans[4]);
        return ans;
    }
};