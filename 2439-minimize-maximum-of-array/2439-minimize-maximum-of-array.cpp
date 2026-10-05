class Solution {
public:
    bool possible(int check,vector<int>& nums){
        int n=nums.size();
        long long test=0;
        for(int i=n-1;i>=0;i--){
           if(nums[i]<check){
            if(test>0)continue;
            else{
                if(check-nums[i]>(-test))test=0;
                else test+=check-nums[i];
            }
           }
           else  test=test+check-nums[i];
        }
       return (test>=0);
    }
    
    int minimizeArrayValue(vector<int>& nums) {
       int n=nums.size();
       long long sum=0;
       for(int i=0;i<n;i++){
        sum+=nums[i];
       }
       int low=sum/n;
       int high=*max_element(nums.begin(),nums.end());
       int mid=low+(high-low)/2;
       int ans;
       while(low<high){
        mid=low+(high-low)/2;
        bool poss=possible(mid,nums);
        if(poss){
            high=mid;
            ans=mid;
        }
        else{
            low=mid+1;
        }
       }
       return low;
    }
};