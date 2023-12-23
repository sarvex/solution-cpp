#include <vector>

class Solution {
public:
  auto isValidSudoku(const std::vector<std::vector<char>>& board) const {
    std::vector row(9, std::vector(9, false));
    std::vector col(9, std::vector(9, false));
    std::vector sub(9, std::vector(9, false));

    for (auto i = 0; i < 9; ++i) {
      for (auto j = 0; j < 9; ++j) {
        const char c = board[i][j];
        if (c == '.') continue;
        const int num = c - '0' - 1;
        const int k = i / 3 * 3 + j / 3;
        if (row[i][num] or col[j][num] or sub[k][num]) return false;
        row[i][num] = col[j][num] = sub[k][num] = true;
      }
    }
    return true;
  }
};
