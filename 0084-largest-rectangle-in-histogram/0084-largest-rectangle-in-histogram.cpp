class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        int n = nums.size();

        vector<int> nse(n);
        vector<int> pse(n);

        stack<int> st;

        int i = 0;

        while(i < n)
        {
            while(!st.empty() && nums[st.top()] >= nums[i])
            {
                st.pop();
            }

            if(st.empty())
                pse[i] = -1;
            else
                pse[i] = st.top();

            st.push(i);
            i++;
        }

        while(!st.empty())
            st.pop();

        i = n - 1;

        while(i >= 0)
        {
            while(!st.empty() && nums[st.top()] >= nums[i])
            {
                st.pop();
            }

            if(st.empty())
                nse[i] = n;
            else
                nse[i] = st.top();

            st.push(i);
            i--;
        }

        int maxarea = 0;

        for(int i = 0; i < n; i++)
        {
            int width = nse[i] - pse[i] - 1;
            maxarea = max(maxarea, width * nums[i]);
        }

        return maxarea;
    }
};