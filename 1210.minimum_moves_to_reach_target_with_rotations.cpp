class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        auto target = make_pair(n * n - 2, n * n - 1);
        queue<pair<int, int>> q;
        q.emplace(0, 1);
        bool vis[n * n][2];
        memset(vis, 0, sizeof vis);
        vis[0][0] = true;

        auto move = [&](int i1, int j1, int i2, int j2) {
            if (i1 >= 0 and i1 < n and j1 >= 0 and j1 < n and i2 >= 0 and i2 < n and j2 >= 0 and j2 < n) {
                int a = i1 * n + j1, b = i2 * n + j2;
                int status = i1 == i2 ? 0 : 1;
                if (!vis[a][status] and grid[i1][j1] == 0 and grid[i2][j2] == 0) {
                    q.emplace(a, b);
                    vis[a][status] = true;
                }
            }
        };

        int ans = 0;
        while (!q.empty()) {
            for (int k = q.size(); k; --k) {
                auto p = q.front();
                q.pop();
                if (p == target) {
                    return ans;
                }
                auto [a, b] = p;
                int i1 = a / n, j1 = a % n;
                int i2 = b / n, j2 = b % n;
                move(i1, j1 + 1, i2, j2 + 1);
                move(i1 + 1, j1, i2 + 1, j2);
                if (i1 == i2 and i1 + 1 < n and grid[i1 + 1][j2] == 0) {
                    move(i1, j1, i1 + 1, j1);
                }
                if (j1 == j2 and j1 + 1 < n and grid[i2][j1 + 1] == 0) {
                    move(i1, j1, i1, j1 + 1);
                }
            }
            ++ans;
        }
        return -1;
    }
};