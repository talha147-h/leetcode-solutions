class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int more;
        map<int,int> mpp;
        for(int i=0;i<nums.size();i++)
        { 
            more=target-nums[i];
            if(mpp.find(more)!=mpp.end())
            return {mpp[more],i};
            else
            mpp[nums[i]]=i;
        }
        return {0};
            
    }

        
};