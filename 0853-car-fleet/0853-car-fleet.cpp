class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        vector<pair<int,int>> vec(n);
        for(int i=0;i<n;i++){
            vec[i]={position[i],speed[i]};
        }
        sort(vec.begin(),vec.end());
        stack<pair<int,int>> st;
        for(int i=0;i<n;i++){
            st.push(vec[i]);
        }
      int cnt=0;
      while(!st.empty()){
        auto [dist,velo]=st.top();
        double time=(double)(target-dist)/velo;
        st.pop();
        cnt++;
        while(!st.empty() && time>=(double)(target-st.top().first)/(double)st.top().second)
        st.pop();
    }
    return cnt;
    }
};