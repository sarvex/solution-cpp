class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if ((i == 0 or i == m - 1 or j == 0 or j == n - 1) and board[i][j] == 'O')
                    dfs(board, i, j);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == '.')
                    board[i][j] = 'O';
                else if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }

    void dfs(vector<vector<char>>& board, int i, int j) {
        board[i][j] = '.';
        vector<int> dirs = {-1, 0, 1, 0, -1};
        for (int k = 0; k < 4; ++k) {
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (x >= 0 and x < board.size() and y >= 0 and y < board[0].size() and board[x][y] == 'O')
                dfs(board, x, y);
        }
    }
};