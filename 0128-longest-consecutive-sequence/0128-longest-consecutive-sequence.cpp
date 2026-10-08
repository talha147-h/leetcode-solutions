class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count;
        int maxm=0;
        int last=85685624;
        int  n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==last+1){
             count++;
            last++;
            }
            else if(nums[i]==last){
                continue;
            }
            else{
                count=1;
                last=nums[i];
            }
            maxm=max(count,maxm);
        }
    return maxm;
    }
};