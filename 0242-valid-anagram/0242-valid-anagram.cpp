class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int>ch;
        
        if(s.length()!=t.length()) return false;
        for(int i=0;i<s.length();i++)
        {
            ch[s[i]]++;
        }
         map<char,int>ch1;
         for(int i=0;i<s.length();i++)
        {
            ch1[t[i]]++;
        }
        if(ch1==ch)return true;
        
        return false;

       
       
        
    }
};