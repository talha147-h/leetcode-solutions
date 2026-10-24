#include<iostream>
#include<vector>
#include<string> 
#include<algorithm>
using namespace std;
class Solution {
public:
    long long countMagicalPairs(string s) {
        int n=s.length();
        vector<vector<int>>L(n+1,vector<int> (27,0));
        vector<int> last_seen(26,-1);
        for(int j=1;j<=n;j++){
            last_seen[s[j-1]-'a']=j-1;
            vector<int> pos=last_seen;
            sort(pos.rbegin(),pos.rend());
            for(int c=1;c<=26 ;c++){
                if(pos[c-1]==-1)break;
                int prev=(c<26)?pos[c]:-1;
                L[j][c]=pos[c-1]-prev;
            }
        }
        long long ans=0;
        vector<int> first_seen(26,n);
        for(int j=n-1;j>=1;--j){
            first_seen[s[j]-'a']=j;
            vector<int> pos=first_seen;
            sort(pos.begin(),pos.end());
            for(int c=1;c<=26;c++){
                if(pos[c-1]==n)break;
                int next=(c<26)?pos[c]:n;
                int r_count=next-pos[c-1];
                ans+=1LL*L[j][c]*r_count;
            }
        }
        return ans;
    }
};