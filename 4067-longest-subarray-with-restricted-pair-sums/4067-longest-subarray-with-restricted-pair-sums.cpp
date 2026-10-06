class Solution {
public:
    bool bad(int x,vector<int>&freq){
        for(int a=1;a<=500;a++){
            if(freq[a]==0)continue;

            int b=x-a;

            if(b>=1&&b<=500&&freq[b]>0){
                if(a!=b||freq[a]>=2){
                    return true;
                }
            }

            b=a+x;

            if(b<=500&&freq[b]>0){
                return true;
            }
        }

        return false;
    }

    int maxSubarray(vector<int>&nums){
        int n=nums.size();
        vector<int>freq(501,0);
        int left=0;
        int ans=0;

        for(int right=0;right<n;right++){
            int x=nums[right];

            while(bad(x,freq)){
                freq[nums[left]]--;
                left++;
            }

            freq[x]++;
            ans=max(ans,right-left+1);
        }

        return ans;
    }
};