class Solution {
public:
   
   long long eats(int speed,vector<int> & piles){
    long long count=0;
    for(int i=0;i<piles.size();i++){
        if(piles[i]%speed==0)count+=piles[i]/speed;
        else count+=piles[i]/speed+1;
    }
   return count;
   }
    int minEatingSpeed(vector<int>& piles, int h) {
        int high=*max_element(piles.begin(),piles.end());
        int low=1;
        int ans=INT_MAX;
        while(low<=high){
        int mid=low+(high-low)/2;
         long long hourstaken=eats(mid,piles);
         if(hourstaken<=h){
             ans=mid;
             high=mid-1;
         }
         else{
             low=mid+1;
         }
        }
        if(ans==INT_MAX)return -1;
        return ans;
    }
};