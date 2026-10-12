class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        long long ans = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq1;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq2;

        int left = 0, right = n - 1;

        for (int i = 0; i < candidates && left <= right; i++) {
            pq1.push({costs[left], left});
            left++;
        }

        for (int i = 0; i < candidates && left <= right; i++) {
            pq2.push({costs[right], right});
            right--;
        }

        while (k--) {
            if (pq2.empty() || (!pq1.empty() && pq1.top() <= pq2.top())) {
                ans += pq1.top().first;
                pq1.pop();

                if (left <= right) {
                    pq1.push({costs[left], left});
                    left++;
                }
            } 
            else {
                ans += pq2.top().first;
                pq2.pop();

                if (left <= right) {
                    pq2.push({costs[right], right});
                    right--;
                }
            }
        }

        return ans;
    }
};