class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            mpp[nums[i]]=i;
        }
        
       set<vector<int>> ans;
        for(int i=0;i<n;i++){
            int target=-nums[i];
            for(int j=i+1;j<n;j++){
                if(mpp.find(target-nums[j])!=mpp.end() && mpp[target-nums[j]]>j){
                    ans.insert({nums[i],nums[j],target-nums[j]});
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