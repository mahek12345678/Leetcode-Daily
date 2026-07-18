class Solution {
public:
    int timer;
    vector<int> dt, low;

    void dfs(
        int u,
        int parent,
        vector<vector<int>>& adj,
        vector<vector<int>>& bridges
    ) {
        dt[u] = low[u] = ++timer;

        for (int v : adj[u]) {
            if (v == parent) {
                continue;
            }

            if (dt[v] == -1) {
                dfs(v, u, adj, bridges);

                low[u] = min(low[u], low[v]);

                if (low[v] > dt[u]) {
                    bridges.push_back({u, v});
                }
            } else {
                low[u] = min(low[u], dt[v]);
            }
        }
    }

    vector<vector<int>> criticalConnections(
        int n,
        vector<vector<int>>& connections
    ) {
        vector<vector<int>> adj(n);

        for (auto& edge : connections) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        timer = 0;
        dt.assign(n, -1);
        low.assign(n, -1);

        vector<vector<int>> bridges;

        for (int i = 0; i < n; i++) {
            if (dt[i] == -1) {
                dfs(i, -1, adj, bridges);
            }
        }

        return bridges;
    }
};