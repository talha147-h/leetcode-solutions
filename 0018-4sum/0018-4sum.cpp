class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums,int target) {
        unordered_map<long long,int> mpp;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            mpp[nums[i]]=i;
        }
    long long x;
    long long k;
       set<vector<int>> ans;
        for(int i=0;i<n;i++){
         x=target-nums[i];
         for(int j=i+1;j<n;j++){
          k=x-nums[j];
            for(int l=j+1;l<n;l++){
                if(mpp.find(k-nums[l])!=mpp.end() && mpp[k-nums[l]]>l){
                    ans.insert({nums[i],nums[j],nums[l],(int)k-nums[l]});
                }
            }
         }
        }
        vector<vector<int>> vec;
        for(auto it: ans){
            vec.push_back(it);
        }
        
        return vec;
    }
};