#include <functional>
#include <string>
#include <vector>

using std::function;
using std::string;
using std::vector;

class Solution {
public:
  auto exist(vector<vector<char>> &board, const string &word) {
    int m = board.size(), n = board[0].size();
    int dirs[5] = {-1, 0, 1, 0, -1};
    function<bool(int, int, int)> dfs = [&](int i, int j, int k) -> bool {
      if (k == word.size() - 1) {
        return board[i][j] == word[k];
      }
      if (board[i][j] != word[k]) {
        return false;
      }
      char c = board[i][j];
      board[i][j] = '0';
      for (int u = 0; u < 4; ++u) {
        int x = i + dirs[u], y = j + dirs[u + 1];
        if (x >= 0 and x < m and y >= 0 and y < n and board[x][y] != '0' and
            dfs(x, y, k + 1)) {
          return true;
        }
      }
      board[i][j] = c;
      return false;
    };
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (dfs(i, j, 0)) {
          return true;
        }
      }
    }
    return false;
  }
};
