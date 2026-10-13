class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;

        vector<vector<pair<int,int>>> adj(n);

        for (int i = 0; i < roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            int time = roads[i][2];

            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            long long time = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (time > dist[node]) continue;

            for (auto it : adj[node]) {
                int nextNode = it.first;
                long long newTime = time + it.second;

                if (newTime < dist[nextNode]) {
                    // Found a shorter path
                    dist[nextNode] = newTime;
                    ways[nextNode] = ways[node];

                    pq.push({newTime, nextNode});
                }
                else if (newTime == dist[nextNode]) {
                    // Found another shortest path
                    ways[nextNode] =
                        (ways[nextNode] + (long long)ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};