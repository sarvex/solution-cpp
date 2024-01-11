#include <functional>
#include <utility>
#include <vector>

class Solution {
public:
  auto solveSudoku(std::vector<std::vector<char>>& board) {
    std::vector row(9, std::vector(9, false));
    std::vector col(9, std::vector(9, false));
    std::vector block(3, std::vector(3, std::vector(9, false)));

    bool ok = false;
    std::vector<std::pair<int, int>> t;

    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        if (board[i][j] == '.') {
          t.emplace_back(i, j);
        } else {
          const int v = board[i][j] - '1';
          row[i][v] = col[j][v] = block[i / 3][j / 3][v] = true;
        }
      }
    }

    const std::function<void(int k)> search = [&](int k) {
      if (k == t.size()) {
        ok = true;
        return;
      }
      const auto [i, j] = t[k];
      for (int v = 0; v < 9; ++v) {
        if (not row[i][v] and not col[j][v] and not block[i / 3][j / 3][v]) {
          row[i][v] = col[j][v] = block[i / 3][j / 3][v] = true;
          board[i][j] = v + '1';
          search(k + 1);
          row[i][v] = col[j][v] = block[i / 3][j / 3][v] = false;
        }
        if (ok) return;
      }
    };
    search(0);
  }
};
