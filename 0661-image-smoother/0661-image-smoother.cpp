class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n=img.size();
        int m=img[0].size();
        int sum=0;
        int cnt=0;
        int avg=0;
        vector<vector<int>> ans(n,vector<int>(m,0));
        for(int i=0;i<img.size();i++)
        {
            for(int j=0;j<img[0].size();j++)
            {
                sum=0;
                cnt=0;
                for(int k=-1;k<=1;k++)
                {
                    for(int l=-1;l<=1;l++)
                    {
                        int nr=i+k;
                        int nc=j+l;
                        if(nr>=0 && nc>=0 && nr<n && nc<m){
                            sum+=img[nr][nc];cnt++;
                        }
                    }
                }
                ans[i][j]=(sum)/cnt;
            }
        }
        return ans;
    }
};