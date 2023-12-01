class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        int m = land.size();
        int n = land[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (land[i][j] == 0 or (j > 0 and land[i][j - 1] == 1) or (i > 0 and land[i - 1][j] == 1)) continue;
                int x = i;
                int y = j;
                for (; x + 1 < m and land[x + 1][j] == 1; ++x)
                    ;
                for (; y + 1 < n and land[x][y + 1] == 1; ++y)
                    ;
                ans.push_back({i, j, x, y});
            }
        }
        return ans;
    }
};