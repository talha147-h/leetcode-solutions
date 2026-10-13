class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums){
        long long ans=0;
        for(int i=0;i<nums.size();i++){
        if(nums[i]<0)nums[i]=-nums[i];
        }
        sort(nums.begin(),nums.end());
        int i=0;int j=nums.size()-1;
        int flag=1;
        while(i<=j){
         if(flag==1){
            ans+=nums[j]*nums[j];
            j--;
            flag=0;
         }
         else{
            ans-=nums[i]*nums[i];
            i++;
            flag=1;
         }
        }
    return ans;
    }
};