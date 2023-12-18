#include <vector>

using std::vector;

class Solution {
public:
  auto spiralOrderFast(const vector<vector<int>>& matrix) {
    vector<int> result;

    int top = 0, bottom = matrix.size() - 1;
    int left = 0, right =  matrix[0].size() - 1;
    while (top <= bottom and left <= right) {
      //top row
      if (top <= bottom) {
        for (int i = left; i <= right; ++i) { result.push_back(matrix[top][i]); }
        top++;
      }

      //right column
      if (left <= right) {
        for (int i = top; i <= bottom; ++i) { result.push_back(matrix[i][right]); }
        right--;
      }

      //bottom row
      if (top <= bottom) {
        for (int i = right; i >= left; --i) { result.push_back(matrix[bottom][i]); }
        bottom--;
      }

      //left column
      if (left <= right) {
        for (int i = bottom; i >= top; --i) { result.push_back(matrix[i][left]); }
        left++;
      }
    }

    return result;
  }

  auto spiralOrder(const vector<vector<int>>& matrix) {
    vector<int> result;

    const vector direction = { 0, 1, 0, -1, 0 };
    const int m = matrix.size(), n = matrix[0].size();
    vector seen(m, vector(n, false));

    for (int h = m * n, i = 0, j = 0, k = 0; h; --h) {
      result.push_back(matrix[i][j]);
      seen[i][j] = true;
      if (const int x = i + direction[k], y = j + direction[k + 1]; x < 0 or x >= m or y < 0 or y >= n or seen[x][y])
        k = (k + 1) % 4;
      i += direction[k];
      j += direction[k + 1];
    }
    return result;
  }
};
