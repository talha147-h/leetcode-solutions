class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int maxlen=0;
        string ans="";

        for(int i=0;i<n;i++){
      
            int left=i,right=i;

            while(left>=0 && right<n && s[left]==s[right]){
                if(right-left+1>maxlen){
                    maxlen=right-left+1;
                    ans=s.substr(left,maxlen);
                }
                left--;
                right++;
            }


            left=i;
            right=i+1;

            while(left>=0 && right<n && s[left]==s[right]){
                if(right-left+1>maxlen){
                    maxlen=right-left+1;
                    ans=s.substr(left,maxlen);
                }
                left--;
                right++;
            }
        }

        return ans;
    }
};