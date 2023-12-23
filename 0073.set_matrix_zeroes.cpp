#include <vector>

using std::vector;

class Solution {
public:
  void setZeroesFast(std::vector<std::vector<int>>& matrix) {
    const int m = matrix.size();
    const int n = matrix[0].size();

    // Create two arrays to track zero columns and rows
    std::vector row(m, false);
    std::vector col(n, false);

    // Iterate through the matrix
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] == 0) {
          // Mark the corresponding row and column as zero
          row[i] = true;
          col[j] = true;
        }
      }
    }

    // Set entire rows to zero
    for (int i = 0; i < m; i++) { if (row[i]) { for (int j = 0; j < n; j++) { matrix[i][j] = 0; } } }

    // Set entire columns to zero
    for (int j = 0; j < n; j++) { if (col[j]) { for (int i = 0; i < m; i++) { matrix[i][j] = 0; } } }
  }

  auto setZeroes(vector<vector<int>>& matrix) {
    const auto m = matrix.size(), n = matrix[0].size();
    bool i0 = false, j0 = false;
    for (int j = 0; j < n; ++j) {
      if (matrix[0][j] == 0) {
        i0 = true;
        break;
      }
    }
    for (int i = 0; i < m; ++i) {
      if (matrix[i][0] == 0) {
        j0 = true;
        break;
      }
    }
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        if (matrix[i][j] == 0) {
          matrix[i][0] = 0;
          matrix[0][j] = 0;
        }
      }
    }
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) { if (matrix[i][0] == 0 or matrix[0][j] == 0) { matrix[i][j] = 0; } }
    }
    if (i0) { for (int j = 0; j < n; ++j) { matrix[0][j] = 0; } }
    if (j0) { for (int i = 0; i < m; ++i) { matrix[i][0] = 0; } }
  }
};
