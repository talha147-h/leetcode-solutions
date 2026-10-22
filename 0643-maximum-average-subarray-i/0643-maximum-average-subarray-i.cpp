class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int left=0;
        int right=0;
        long long sum=0;
        double avg=0.0;
        double maxavg=INT_MIN;
        for(right=0;right<nums.size();right++)
        {
            sum+=nums[right];
            if(right-left+1==k)
            {
                avg=(double)sum/k;
                maxavg=max(maxavg,avg);
                sum-=nums[left];
                left++;
            }
        }
return maxavg;
        
    }
};