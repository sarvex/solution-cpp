#include <vector>

using std::vector;

class Solution {
public:
  auto isValidSudoku(vector<vector<char>>& board) -> bool {
    vector<vector<bool>> row(9, vector<bool>(9, false));
    vector<vector<bool>> col(9, vector<bool>(9, false));
    vector<vector<bool>> sub(9, vector<bool>(9, false));

    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        char c = board[i][j];
        if (c == '.')
          continue;
        int num = c - '0' - 1;
        int k = i / 3 * 3 + j / 3;
        if (row[i][num] or col[j][num] or sub[k][num]) {
          return false;
        }
        row[i][num] = true;
        col[j][num] = true;
        sub[k][num] = true;
      }
    }
    return true;
  }
};
