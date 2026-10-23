class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> mpp;
        for(int x:arr){
            mpp[x]++;
        }
        priority_queue<int> pq;
        int len=arr.size();
        for(auto it: mpp)
        pq.push(it.second);
        int sum=0;
        int ans=0;
        while(sum<(len/2))
        {
                sum+=pq.top();
                pq.pop();
                ans++;
        }
        return ans;
    }
};