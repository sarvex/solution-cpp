#include <vector>

using std::vector;

class Solution {
public:
  auto searchMatrix(const vector<vector<int>> &matrix, int target) {
    auto m = matrix.size(), n = matrix[0].size();
    int left = 0, right = m * n - 1;
    while (left < right) {
      int mid = left + right >> 1;
      int x = mid / n, y = mid % n;
      if (matrix[x][y] >= target) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    return matrix[left / n][left % n] == target;
  }
};
