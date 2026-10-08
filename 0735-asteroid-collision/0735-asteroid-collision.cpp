class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
     stack<int> st;
     int n=asteroids.size();
     for(int i=n-1;i>=0;i--)
     {
        if(st.empty()||(st.top()>0&&asteroids[i]<0)||(st.top()>0&&asteroids[i]>0)||(st.top()<0&&asteroids[i]<0))
        {
            st.push(asteroids[i]);
            continue;
        }
        else if(st.top()<0&&asteroids[i]>0)
        {
            while((st.top()<0)&&(-(st.top()))<asteroids[i])
            {
            st.pop();
            if(st.empty())break;
            }
            if(st.empty()||st.top()>0)
            st.push(asteroids[i]);
            else if(-(st.top())==asteroids[i])
            st.pop();

        }
     }
     vector <int> v;
     while(!(st.empty()))
     {
        v.push_back(st.top());
        st.pop();
     }
     return v;   
    }
};