class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
       if(nums.size()==0)return 0;
        int prev=nums[0];
        int n=nums.size();
        int count=1;
        int mxcount=0;
        for(int i=0;i<n;i++){
            if(nums[i]-prev==1){
                count++;

            }
            else if(nums[i]==prev){
                count=count;
            }
            else{
                count=1;
            }
            prev=nums[i];
            mxcount=max(count,mxcount);
        }
        return mxcount;
    }
};