
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto &f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }

     
        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;

        pq.push({0, {src, 0}});

        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
        dist[src][0] = 0;

        while (!pq.empty()) {
            int cost = pq.top().first;
            int node = pq.top().second.first;
            int flightsTaken = pq.top().second.second;
            pq.pop();

            if (node == dst)
                return cost;

            if (flightsTaken == k + 1)
                continue;

            if (cost > dist[node][flightsTaken])
                continue;

            for (auto it : adj[node]) {
                int nextNode = it.first;
                int nextCost = cost + it.second;
                int nextFlights = flightsTaken + 1;

                if (nextCost < dist[nextNode][nextFlights]) {
                    dist[nextNode][nextFlights] = nextCost;
                    pq.push({nextCost, {nextNode, nextFlights}});
                }
            }
        }

        return -1;
    }
};
