class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      unordered_map<char,int> mpp;
      int left=0;
      int right=0;
      int maxlen=0;
      while(right<s.size() && left<=right){
        char ch=s[right];
        while(mpp.find(ch)!=mpp.end()){
            mpp.erase(s[left]);
            left++;
        }
        mpp[ch]=1;
         maxlen=max(maxlen,right-left+1);
         right++;
      } 
      return maxlen; 
    }
};