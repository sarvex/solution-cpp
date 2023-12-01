class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        int dirs[5] = {-1, 0, 1, 0, -1};
        function<int(int, int)> dfs = [&](int i, int j) -> int {
            int res = i > 0 and i < m - 1 and j > 0 and j < n - 1 ? 1 : 0;
            grid[i][j] = 1;
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 and x < m and y >= 0 and y < n and grid[x][y] == 0) {
                    res &= dfs(x, y);
                }
            }
            return res;
        };
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans += grid[i][j] == 0 and dfs(i, j);
            }
        }
        return ans;
    }
};