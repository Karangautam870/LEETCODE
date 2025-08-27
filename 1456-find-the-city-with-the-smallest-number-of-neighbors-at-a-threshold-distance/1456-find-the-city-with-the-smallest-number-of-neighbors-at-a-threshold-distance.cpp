#define p pair<int, int>
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int k) {
        vector<vector<p>> adj(n);

        for (auto& it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        int ans = -1, mini = INT_MAX;

        for (int src = 0; src < n; src++) {

            vector<int> dist(n, INT_MAX);
            priority_queue<p, vector<p>, greater<p>> pq;
            pq.push({0, src});
            dist[src] = 0;

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

            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (i != src && dist[i] <= k) {
                    cnt++;
                }
            }

            if (cnt < mini || (cnt == mini && src > ans)) {
                mini = cnt;
                ans = src;
            }
        }

        return ans;
    }
};
