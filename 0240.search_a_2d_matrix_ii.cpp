#include <vector>

class Solution {
public:
  auto searchMatrix(const std::vector<std::vector<int>>& matrix, const int target) {
    const auto m = static_cast<int>(matrix.size()), n = static_cast<int>(matrix[0].size());

    for (int j = 0, i = m - 1; i >= 0 and j < n;) {
      if (matrix[i][j] == target) return true;
      if (matrix[i][j] > target) --i;
      else ++j;
    }
    return false;
  }
};
