class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        vector<int>find(n+1,1);
        for(int i=0;i<n;i++){
        if(find[nums[i]]==1)find[nums[i]]=0;
        else find[nums[i]]=-1;
        }
        int ans;
        for(int i=0;i<n;i++){
            if(find[i]==-1){ans=i;break;}
        }
        return ans;
    }
};