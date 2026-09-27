class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        map<int,int> freq;
        for(int x : nums)
            freq[x]++;

        vector<int> ans;      
        while(!freq.empty()) {

            for(auto it = freq.begin(); it != freq.end(); ) {
                ans.push_back(it->first);
                it->second--;
                if(it->second == 0)
                    it = freq.erase(it);
                else
                    it++;
            }
        }

        return ans;
    }
};