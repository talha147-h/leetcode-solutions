class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int count=-1;
        vector<int> ans;
        for(int i=0;i<seq.size();i++){
            if(seq[i]=='(')
               {
                count++;
                ans.push_back(count%2);
                }
                else
                {
                    ans.push_back(count%2);
                    count--;
                }
        }
        return ans;
    }
};