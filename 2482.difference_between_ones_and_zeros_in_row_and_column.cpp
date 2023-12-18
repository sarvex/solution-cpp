#include <vector>

using std::vector;

class Solution {
public:
  auto onesMinusZeros(const vector<vector<int>> &grid) {
    auto m = grid.size(), n = grid[0].size();
    vector<int> row(m);
    vector<int> col(n);
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        int v = grid[i][j];
        row[i] += v;
        col[j] += v;
      }
    }
    vector<vector<int>> result(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        result[i][j] = 2 * row[i] + 2 * col[j] - m - n;
      }
    }
    return result;
  }
};
