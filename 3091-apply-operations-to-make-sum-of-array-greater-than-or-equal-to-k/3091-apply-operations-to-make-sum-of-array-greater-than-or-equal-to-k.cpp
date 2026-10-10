class Solution {
public:
    int minOperations(int k) {
        int ans=INT_MAX;
      for(int i=1;i<=k;i++){
       int moves=(k-1)/i;
       moves=i-1+moves;
       ans=min(ans,moves);
      }
      return ans;
    }
};