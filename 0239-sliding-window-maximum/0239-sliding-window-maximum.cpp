class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        int start=0;
        int n=nums.size();
        vector<int> res;
        for(int i=0;i<n;i++)
        {
            if(!q.empty() && q.front()<i-k+1)q.pop_front();
                while(!q.empty() && nums[q.back()]<=nums[i])q.pop_back();
                q.push_back(i);   
            if(i>=k-1)res.push_back(nums[q.front()]);

        }
        return res;
    }
};