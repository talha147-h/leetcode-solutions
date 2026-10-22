class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        priority_queue<int,vector<int>,greater<int>> pq;
        int day=1;
        int count=0;
        int i=0;
        int n=events.size();
        while(i<n || !pq.empty()){
            if(pq.empty())
            day=events[i][0];
            while(i<n &&day==events[i][0]){
                pq.push(events[i][1]);
                i++;
            }
           while (!pq.empty() && day>pq.top())pq.pop();
            
            if(!pq.empty()){
                pq.pop();
                day++;
                count++;
            }
        }
        return count;
    }
};