class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> mpp;
        string word = "";

        for(char ch : paragraph) {
            if(!isalpha(ch)){                
            if(word != "") {
                mpp[word]++;
                    word = "";
                }
            }
            else {
                if(ch >= 'A' && ch <= 'Z')
                    ch += 32;

                word += ch;
            }
        }

        if(word != "")
            mpp[word]++;

        int highestcnt = 0;
        string ans = "";

        for(auto it : mpp) {
            bool ban = false;

            for(int i = 0; i < banned.size(); i++) {
                if(banned[i] == it.first) {
                    ban = true;
                    break;
                }
            }

            if(ban)
                continue;

            if(it.second > highestcnt) {
                highestcnt = it.second;
                ans = it.first;
            }
        }

        return ans;
    }
};