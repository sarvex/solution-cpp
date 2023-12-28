class Solution {
public:
    int n;
    int result;
    vector<bool> vis;
    unordered_map<int, vector<int>> match;

    int countArrangement(int n) {
        this->n = n;
        this->result = 0;
        vis.resize(n + 1);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (i % j == 0 or j % i == 0)
                    match[i].push_back(j);
        dfs(1);
        return result;
    }

    void dfs(int i) {
        if (i == n + 1) {
            ++result;
            return;
        }
        for (int j : match[i]) {
            if (!vis[j]) {
                vis[j] = true;
                dfs(i + 1);
                vis[j] = false;
            }
        }
    }
};