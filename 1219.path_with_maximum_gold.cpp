class Solution {
public:
    vector<int> dirs = {-1, 0, 1, 0, -1};

    int getMaximumGold(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[0].size(); ++j)
                ans = max(ans, dfs(i, j, grid));
        return ans;
    }

    int dfs(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 or i >= grid.size() or j < 0 or j >= grid[0].size() or grid[i][j] == 0) return 0;
        int t = grid[i][j];
        grid[i][j] = 0;
        int ans = 0;
        for (int k = 0; k < 4; ++k) ans = max(ans, t + dfs(i + dirs[k], j + dirs[k + 1], grid));
        grid[i][j] = t;
        return ans;
    }
};