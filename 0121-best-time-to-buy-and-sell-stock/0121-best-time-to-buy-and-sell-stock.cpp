class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minm=prices[0];
        int ans=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]<minm)
            minm=prices[i];
            else
            ans=max(ans,prices[i]-minm);
        }
        return ans;
    }
};