class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
     vector<vector<int>> ans;
     sort(intervals.begin(),intervals.end());
    
     for(int i=0;i<intervals.size();i++){
       int start=intervals[i][0];
     int end=intervals[i][1];
     int j=i+1;
     while(j<intervals.size()&& end>=intervals[j][0]){
        end=max(end,intervals[j][1]);
        j++;
     }
     i=j-1;
     ans.push_back({start,end});
     }   
     return ans;
    }
};