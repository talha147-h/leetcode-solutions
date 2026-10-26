class Solution {
public:
    int countStaircase(vector<int>& nums) {
        vector<int> freq;
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            vector<int> freq;
            unordered_map<int,int> mpp;
            for(int j=i;j<n;j++){
                if(mpp.find(nums[j])==mpp.end()){
                    {freq.push_back(1);
                    mpp[nums[j]]=freq.size()-1;}
                }
                else{
                    freq[mpp[nums[j]]]++;
                }
                bool ok=true;
                for(int t=0;t<freq.size();t++){
                    if(freq[t]!=t+1){
                        ok=false; break;
                    }
                }
                if(ok)cnt++;
            }
        }
        return cnt;
    }
};