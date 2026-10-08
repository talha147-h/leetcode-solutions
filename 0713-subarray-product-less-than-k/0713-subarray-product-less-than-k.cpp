class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1)return 0;
        long long product=1;
        int ans=0;
       int start=0;
        for(int i=0;i<nums.size();i++){
        product*=nums[i];
       while(product>=k){
        product=product/nums[start];
        start++;
       }
       ans+=i-start+1;
        }
        return ans;
    }
};