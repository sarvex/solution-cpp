class Solution {
public:
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        function<bool(int, int)> dfs = [&](int i, int j) -> bool {
            if (i >= m or j >= n or grid[i][j] == 0) {
                return false;
            }
            if (i == m - 1 and j == n - 1) {
                return true;
            }
            grid[i][j] = 0;
            return dfs(i + 1, j) or dfs(i, j + 1);
        };
        bool a = dfs(0, 0);
        grid[0][0] = grid[m - 1][n - 1] = 1;
        bool b = dfs(0, 0);
        return !(a and b);
    }
};