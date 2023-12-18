#include <vector>

using std::vector;

class Solution {
public:
  auto numSpecial(const vector<vector<int>> &mat) {
    auto m = mat.size(), n = mat[0].size();
    vector<int> row(m), col(n);
    for (auto i = 0; i < m; ++i) {
      for (auto j = 0; j < n; ++j) {
        if (mat[i][j] == 1) {
          ++row[i];
          ++col[j];
        }
      }
    }
    int result = 0;
    for (auto i = 0; i < m; ++i) {
      for (auto j = 0; j < n; ++j) {
        if (mat[i][j] == 1 and row[i] == 1 and col[j] == 1) {
          ++result;
        }
      }
    }
    return result;
  }
};
