class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
    // -->((nums[i]%k)+k)%k for negative nos.
    unordered_map<int,int> mpp;
    for(int i=0;i<arr.size();i++){
        int rem=((arr[i]%k)+k)%k;
        mpp[rem]++;
    }
    for(auto it : mpp)
     {
        if(it.first==0){
            if(it.second%2!=0)return false;
        }
       else  if(mpp[k-it.first]!=it.second)return false;
     }
    
    return true;
    }
};