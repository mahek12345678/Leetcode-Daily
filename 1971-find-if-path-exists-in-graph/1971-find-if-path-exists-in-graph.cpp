class Solution {
public:
    void dfs(int u, vector<vector<int>>& adj, vector<bool>& vis) {
        vis[u] = true;

        for (int v : adj[u]) {
            if (!vis[v]) {
                dfs(v, adj, vis);
            }
        }
    }

    bool validPath(int n, vector<vector<int>>& edges,
                   int source, int destination) {

        vector<vector<int>> adj(n);

        for (auto edge : edges) {
            int a = edge[0];
            int b = edge[1];

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<bool> vis(n, false);

        dfs(source, adj, vis);

        return vis[destination];
    }
};