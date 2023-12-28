#include <vector>

class Solution {
public:
  int maximalSquare(std::vector<std::vector<char>>& matrix) {
    const int m = matrix.size(), n = matrix[0].size();
    std::vector map(m + 1, std::vector(n + 1, 0));
    int length = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (matrix[i][j] == '1') {
          map[i + 1][j + 1] = 1 + std::min(std::min(map[i][j + 1], map[i + 1][j]), map[i][j]);
          length = std::max(length, map[i + 1][j + 1]);
        }
      }
    }
    return length * length;
  }
};
