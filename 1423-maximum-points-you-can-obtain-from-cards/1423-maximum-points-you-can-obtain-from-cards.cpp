class Solution {
public:
//[1,2,3,4,5,6,7,1] --- k=3
//[1,3,6,10,15,21,28,29]--->map
    int maxScore(vector<int>& cardPoints, int k) {
        long long sum=0;
        unordered_map<int,int> mpp;
        for(int i=0;i<cardPoints.size();i++)
      {
        sum+=cardPoints[i];
        mpp[i]=sum;
      }
         if(k==cardPoints.size())return sum;
        int left=0;
        int right=cardPoints.size()-k-1;
        int minm=INT_MAX;
         while(right<cardPoints.size()){
           minm=min(minm,mpp[right]-mpp[left]+cardPoints[left]); 
           left++;
           right++;
         }
         return sum-minm;
    }
};