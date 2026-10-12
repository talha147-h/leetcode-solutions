class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]-i]++;
        }
        long long cnt=0;
        for(auto it: mpp){
            if(it.second>=2)
            cnt+=1LL*it.second*(it.second-1)/2;
        }
        int n=nums.size();
       long long ans=1LL*n*(n-1)/2-cnt;
       return ans;

    }
};