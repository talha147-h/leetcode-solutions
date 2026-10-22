class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
      vector<long long> prefix(n,1);
      int prod=1;
      
      for(int i=1;i<n;i++)
      {
        prod=prod*nums[i-1];
        prefix[i]=prod;
      }
      
       prod=1;  
      vector<long long> suffix(n,1);
  
       for(int i=n-2;i>=0;i--)
      {
        prod=prod*nums[i+1];
        suffix[i]=prod;
      }
      
      vector<int> ans(n,1);
      for(int i=0;i<n;i++)
      {
        ans[i]=suffix[i]*prefix[i];
      }
      return ans;
    }
};