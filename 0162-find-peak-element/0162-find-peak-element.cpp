class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
         int high=n-1;
         int low=0;
         while(low<high){
            int mid=low+(high-low)/2;
            if((mid==0 && nums[mid+1]<nums[mid]) || (mid==n-1 && nums[mid]>nums[mid-1]) || (nums[mid]>nums[mid+1]&& nums[mid]>nums[mid-1]))
            return mid;
            if((mid>0 && nums[mid]<nums[mid-1]))
                high=mid-1;
            else if((mid<n-1 && nums[mid]<nums[mid+1]))
            low=mid+1;
         }
         return low;
    }
};