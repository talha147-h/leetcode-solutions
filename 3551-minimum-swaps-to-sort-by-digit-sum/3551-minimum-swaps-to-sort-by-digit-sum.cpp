class Solution {
public:
    int minSwaps(vector<int>& nums) {
      vector<pair<int,int>> arr;
      for(int i=0;i<nums.size();i++){
        int dsum=0;
        int x=nums[i];
        while(x>0){
            dsum+=x%10;
            x=x/10;
        }
        arr.push_back({dsum,nums[i]});
      }
      map<pair<int,int>,int> mpp;
      vector<pair<int,int>> sorted=arr;
      sort(sorted.begin(),sorted.end());
      for(int i=0;i<sorted.size();i++){
        mpp[sorted[i]]=i;
      }
      int count =0;
      for(int i=0;i<arr.size();i++){
        while(mpp[arr[i]]!=i){
            swap(arr[i],arr[mpp[arr[i]]]);
            count++;
        }
      }
      return count;
    }
};