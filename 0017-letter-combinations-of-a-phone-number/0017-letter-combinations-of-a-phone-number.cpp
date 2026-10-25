class Solution {
public:
    void solve(int i,string digits,vector<string> &ans,string curr){
        int n=digits.size();
        if(i==n){
            ans.push_back(curr);
            return;
        }
        char ch=digits[i];
        if(ch=='2'){
            for(char c='a';c<='c';c++){
                curr.push_back(c);
                solve(i+1,digits,ans,curr);
                curr.pop_back();
            }
        }
        else if(ch=='3'){
            for(char c='d';c<='f';c++){
                curr.push_back(c);
                solve(i+1,digits,ans,curr);
                curr.pop_back();
            }
        }
         else if(ch=='4'){
            for(char c='g';c<='i';c++){
                curr.push_back(c);
                solve(i+1,digits,ans,curr);
                curr.pop_back();
            }
        }
         else if(ch=='5'){
            for(char c='j';c<='l';c++){
                curr.push_back(c);
                solve(i+1,digits,ans,curr);
                curr.pop_back();
            }
        } else if(ch=='6'){
            for(char c='m';c<='o';c++){
                curr.push_back(c);
                solve(i+1,digits,ans,curr);
                curr.pop_back();
            }
        }
         else if(ch=='7'){
            for(char c='p';c<='s';c++){
                curr.push_back(c);
                solve(i+1,digits,ans,curr);
                curr.pop_back();
            }
        } else if(ch=='8'){
            for(char c='t';c<='v';c++){
                curr.push_back(c);
                solve(i+1,digits,ans,curr);
                curr.pop_back();
            }
        }
         else if(ch=='9'){
            for(char c='w';c<='z';c++){
                curr.push_back(c);
                solve(i+1,digits,ans,curr);
                curr.pop_back();
            }
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string curr="";
        solve(0,digits,ans,curr);
        return ans;
    }
};