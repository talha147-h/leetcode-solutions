class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        long long sum=0;
        int cnt=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int rem=((sum%k)+k)%k;
            if(sum%k==0)cnt++;
            if(mpp.find(rem)!=mpp.end()){
                cnt+=mpp[rem];
            }
            mpp[rem]++;
        }
        return cnt;
    }
};