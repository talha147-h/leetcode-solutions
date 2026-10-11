class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1)return true;
        int lastidx=nums.size()-1;
        int i=nums.size()-2;
        while(i>=0){
            if(nums[i]+i>=lastidx){
                lastidx=i;
                if(i==0)return true;
            }
            i--;
        }
        return false;
    }
};