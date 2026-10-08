class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adjlist(numCourses);
        vector<int> indegree(numCourses);
        if(prerequisites.empty())return true;
        int n=prerequisites.size();
        for(int i=0;i<n;i++){
        indegree[prerequisites[i][0]]++;
        adjlist[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }   
        int node;
          queue<int> q;
        for(int i=0;i<numCourses;i++){
           if(indegree[i]==0){q.push(i);}
        }
        int count=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            count++;
            for(auto x:adjlist[node]){
                indegree[x]--;
                if(indegree[x]==0)q.push(x);
            }
        }
        return (count==numCourses);
 }
};