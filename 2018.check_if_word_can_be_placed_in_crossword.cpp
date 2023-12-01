class Solution {
public:
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        int k = word.size();
        auto check = [&](int i, int j, int a, int b) {
            int x = i + a * k, y = j + b * k;
            if (x >= 0 and x < m and y >= 0 and y < n and board[x][y] != '#') {
                return false;
            }
            for (char& c : word) {
                if (i < 0 or i >= m or j < 0 or j >= n or (board[i][j] != ' ' and board[i][j] != c)) {
                    return false;
                }
                i += a;
                j += b;
            }
            return true;
        };
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                bool leftToRight = (j == 0 or board[i][j - 1] == '#') and check(i, j, 0, 1);
                bool rightToLeft = (j == n - 1 or board[i][j + 1] == '#') and check(i, j, 0, -1);
                bool upToDown = (i == 0 or board[i - 1][j] == '#') and check(i, j, 1, 0);
                bool downToUp = (i == m - 1 or board[i + 1][j] == '#') and check(i, j, -1, 0);
                if (leftToRight or rightToLeft or upToDown or downToUp) {
                    return true;
                }
            }
        }
        return false;
    }
};