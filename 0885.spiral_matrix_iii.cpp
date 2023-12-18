#include <vector>
#include <algorithm>

using std::vector;
using std::max;

class Solution {
public:
  vector<vector<int>> spiralMatrixIIIFast(int rows, int cols, int rStart, int cStart) {
    vector<vector<int>> result{{rStart, cStart}};
    const int offset = max(max(rStart, cStart), max(rows-rStart, cols-cStart));
    for (int i = 1, row = 0, column = 0;i <= offset; ++i) {
      // right line
      column = cStart + i;
      for (row = rStart - i + 1; row <= rStart + i; ++row) {
        if (row < rows and row >= 0 and column < cols and column >= 0) {
          result.push_back({row, column});
        }
      }
      // bottom line
      row = rStart + i;
      for (column = cStart + i - 1; column >= cStart - i; --column) {
        if (row < rows and row >= 0 and column < cols and column >= 0) {
          result.push_back({row, column});
        }
      }
      // left line
      column = cStart - i;
      for (row = rStart + i - 1; row >= rStart - i; --row) {
        if (row < rows and row >= 0 and column < cols and column >= 0) {
          result.push_back({row, column});
        }
      }
      // top line
      row = rStart - i;
      for (column = cStart - i + 1; column <= cStart + i; ++column) {
        if (row < rows and row >= 0 and column < cols and column >= 0) {
          result.push_back({row, column});
        }
      }
    }

    return result;
  }

  vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
    vector<vector<int>> result{ { rStart, cStart } };
    const int count = rows * cols;
    if (count == 1) return result;
    for (int k = 1;; k += 2) {
      for (vector<vector<int>> directions{ { 0, 1, k }, { 1, 0, k }, { 0, -1, k + 1 }, { -1, 0, k + 1 } };
           const auto& direction: directions) {
        for (int row = direction[0], column = direction[1], layer = direction[2]; layer > 0; --layer) {
          rStart += row;
          cStart += column;
          if (rStart >= 0 and rStart < rows and cStart >= 0 and cStart < cols) {
            result.push_back({ rStart, cStart });
            if (result.size() == count) return result;
          }
        }
      }
    }
  }
};
