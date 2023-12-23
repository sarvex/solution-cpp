#include <vector>

class Solution {
public:
  void gameOfLife(std::vector<std::vector<int>>& board) {
    const int m = board.size(), n = board[0].size();
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        int live = -board[i][j];
        for (int x = i - 1; x <= i + 1; ++x) {
          for (int y = j - 1; y <= j + 1; ++y) {
            if (x >= 0 and x < m and y >= 0 and y < n and board[x][y] > 0) { ++live; }
          }
        }
        if (board[i][j] == 1 and (live < 2 or live > 3)) { board[i][j] = 2; }
        if (board[i][j] == 0 and live == 3) { board[i][j] = -1; }
      }
    }
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (board[i][j] == 2) { board[i][j] = 0; } else if (board[i][j] == -1) { board[i][j] = 1; }
      }
    }
  }
};
