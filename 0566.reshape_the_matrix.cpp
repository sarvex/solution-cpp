#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> matrixReshape(const std::vector<std::vector<int>>& mat, const int r, const int c) {
    const int m = mat.size(), n = mat[0].size();
    const int size = m * n;
    if (m * n != r * c) { return mat; }

    std::vector result(r, std::vector (c, 0));
    for (int i = 0; i < size; ++i) { result[i / c][i % c] = mat[i / n][i % n]; }
    return result;
  }
};
