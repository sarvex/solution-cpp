class Solution {
public:
    vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    int n = 8;

    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        for (auto& d : dirs) {
            int a = d[0], b = d[1];
            int i = rMove, j = cMove;
            int t = 0;
            while (0 <= i + a and i + a < n and 0 <= j + b and j + b < n) {
                ++t;
                i += a;
                j += b;
                if (board[i][j] == '.' or board[i][j] == color) break;
            }
            if (board[i][j] == color and t > 1) return true;
        }
        return false;
    }
};