#include <vector>

using std::vector;

class Solution {
public:
  vector<vector<int>> generateMatrixFast(const int n) {
    vector result (n, vector<int>(n));
    int count = 1;
    for (int layer = 0; layer < (n + 1) / 2; layer++) {
      for (int i = layer; i < n - layer; ++i)
        result[layer][i] = count++;
      for (int i = layer + 1; i < n - layer; ++i)
        result[i][n - layer - 1] = count++;
      for (int i = n - layer - 2; i >= layer; --i)
        result[n - layer - 1][i] = count++;
      for (int i = n - layer - 2; i > layer; --i)
        result[i][layer] = count++;
    }
    return result;
  }

  constinit vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  auto generateMatrix(int n) {
    const int size = n * n;
    vector result(n, vector<int>(n));
    int i = 0, j = 0, k = 0;
    for (int v = 1; v <= size; ++v) {
      result[i][j] = v;
      int x = i + directions[k][0], y = j + directions[k][1];
      if (x < 0 or y < 0 or x >= n or y >= n or result[x][y]) {
        k = (k + 1) % 4;
        x = i + directions[k][0], y = j + directions[k][1];
      }
      i = x, j = y;
    }
    return result;
  }
};
