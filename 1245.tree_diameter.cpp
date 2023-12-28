class Solution {
public:
    unordered_map<int, unordered_set<int>> g;
    vector<bool> vis;
    int result;
    int next;

    int treeDiameter(vector<vector<int>>& edges) {
        for (auto& e : edges) {
            g[e[0]].insert(e[1]);
            g[e[1]].insert(e[0]);
        }
        int n = edges.size();
        result = 0;
        vis.resize(n + 1);
        next = edges[0][0];
        dfs(next, 0);
        vis.assign(vis.size(), false);
        dfs(next, 0);
        return result;
    }

    void dfs(int u, int t) {
        if (vis[u]) return;
        vis[u] = true;
        if (result < t) {
            result = t;
            next = u;
        }
        for (int v : g[u]) dfs(v, t + 1);
    }
};