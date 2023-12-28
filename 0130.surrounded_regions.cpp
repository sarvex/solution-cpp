#include <functional>
#include <vector>

class Solution {
public:
  void solve(std::vector<std::vector<char>>& board) {
    const int m = board.size(), n = board[0].size();

    std::function<void(int, int)> search = [&](const int i, const int j) {
      board[i][j] = '.';
      const std::vector dirs = { -1, 0, 1, 0, -1 };
      for (int k = 0; k < 4; ++k) {
        const int x = i + dirs[k], y = j + dirs[k + 1];
        if (x >= 0 and x < m and y >= 0 and y < n and board[x][y] == 'O')
          search(x, y);
      }
    };
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if ((i == 0 or i == m - 1 or j == 0 or j == n - 1) and board[i][j] == 'O')
          search(i, j);
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (board[i][j] == '.')
          board[i][j] = 'O';
        else if (board[i][j] == 'O')
          board[i][j] = 'X';
      }
    }
  }
};
