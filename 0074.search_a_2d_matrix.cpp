#include <vector>

class Solution {
public:
  bool searchMatrixFast(const std::vector<std::vector<int>>& matrix, int target) {
    int left = 0;
    int right = matrix.size() * matrix[0].size() - 1;
    const int size = matrix[0].size();

    while (left <= right) {
      if (const int mid = left + ((right - left) >> 1), row = mid / size, col = mid % size;
        matrix[row][col] > target) right = mid - 1;
      else if (matrix[row][col] < target) left = mid + 1;
      else if (matrix[row][col] == target) {
        return true;
      }
    }
    return false;
  }


  auto searchMatrix(const std::vector<std::vector<int>>& matrix, int target) {
    const int m = matrix.size(), n = matrix[0].size();
    int left = 0, right = m * n - 1;
    while (left < right) {
      if (const int mid = left + ((right - left) >> 1), x = mid / n, y = mid % n; matrix[x][y] >= target) right = mid;
      else left = mid + 1;
    }
    return matrix[left / n][left % n] == target;
  }
};
