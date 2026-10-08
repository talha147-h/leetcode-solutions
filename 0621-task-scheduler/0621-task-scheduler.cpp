class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int>pq;
        unordered_map<char,int> freq;
        for(char ch: tasks){
            freq[ch]++;
        }
        int time=0;
        queue<pair<int,int>> q;
        for(auto it: freq){
            pq.push(it.second);
        }
        while(!pq.empty() || !q.empty()){
            time++;
            while(!q.empty() && q.front().second<=time){
                auto[frq,cooldown]=q.front();
                pq.push(frq);
            q.pop();
            }
            if(pq.empty())continue;
            else{
               int x=pq.top();
               pq.pop();
               if(x-1>0)
               q.push({x-1,time+n+1});
            }
        }
        return time;
    }
};