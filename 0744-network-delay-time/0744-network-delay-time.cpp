#define p pair<int, int>
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<p>> adj(n+1);

        for (auto& it : times) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
        }

        vector<int> dist(n + 1, INT_MAX);

        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0, k});
        dist[k] = 0;

        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;

            pq.pop();

            for (auto& edg : adj[u]) {
                int v = edg.first;
                int wt = edg.second;

                if (dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                    pq.push({dist[v], v});
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) {
                return -1;
            }
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};