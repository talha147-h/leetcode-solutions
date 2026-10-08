class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size(), character = 0;
        if (n > m)
            return "";
        int minSize = INT_MAX;
        unordered_map<char, int> tChars;
        for (int i = 0; i < n; i++)
            tChars[t[i]]++;
        int mapSize = tChars.size();
        int i = 0;
        int j = 0,start= 0;
        while (j < m) {
            if (tChars.find(s[j]) != tChars.end()) {
                tChars[s[j]]--;
                if (tChars[s[j]] == 0) character++;
            }
            while(mapSize == character) {
                if(j-i+1 < minSize){
                    minSize= j-i+1;
                    start= i;
                }
                if(tChars.find(s[i]) != tChars.end()){
                    tChars[s[i]]++;
                    if (tChars[s[i]] == 1) character--;
                }
                i++;
            } 
            j++;
        }
        return minSize == INT_MAX ? "" : s.substr(start,minSize);
    }
};