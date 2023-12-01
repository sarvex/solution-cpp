class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(), n = image[0].size();
        int oc = image[sr][sc];
        int dirs[5] = {-1, 0, 1, 0, -1};
        function<void(int, int)> dfs = [&](int i, int j) {
            if (i < 0 or i >= m or j < 0 or j >= n or image[i][j] != oc or image[i][j] == color) {
                return;
            }
            image[i][j] = color;
            for (int k = 0; k < 4; ++k) {
                dfs(i + dirs[k], j + dirs[k + 1]);
            }
        };
        dfs(sr, sc);
        return image;
    }
};