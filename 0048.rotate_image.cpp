#include <algorithm>
#include <vector>

class Solution {
public:
  auto rotate(const std::vector<std::vector<int>>& matrix) const {
    const auto n = matrix.size();
    const auto m = n >> 1;
    for (auto i = 0; i < m; ++i) { for (auto j = 0; j < n; ++j) { std::swap(matrix[i][j], matrix[n - i - 1][j]); } }
    for (auto i = 0; i < n; ++i) { for (auto j = 0; j < i; ++j) { std::swap(matrix[i][j], matrix[j][i]); } }
  }
};
