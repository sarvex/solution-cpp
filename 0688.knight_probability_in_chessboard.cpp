#include <functional>
#include <vector>

using std::function;
using std::vector;

class Solution {
public:
  double knightProbabilityFast(int n, int k, int row, int column) {
    // f(i,j,k) => Probability hat after K moves from i,j knight remains inside the board
    // f(i,j,k) = f(i+1,j+2,k-1)*(1/8) + f(i+2,j+1,k-1)*(1/8) + f(i-1,j+2,k-1)*(1/8) + f(i-2,j+1,k-1)*(1/8) + f(i+1,j-2,k-1)*(1/8) + f(i+2,j-1,k-1)*(1/8) + f(i-1,j-2,k-1)*(1/8) + f(i-1,j-1,k-1)*(1/8);
    // Base case: if(i<0 || j<0 || i>=n || j>=n) return 0;
    // if(k==0) return 1
    // Two directional arrays are made => dx,dy
    // dx=[1,2,-1,-2,1,2,-1,-2]
    // dy=[2,1,2,1,-2,-1,-2,-1]
    // f(i,j,k) = summation of f(i+dx[m],h+dy[m],k-1)*(1/8) for all m belongs to [0,7];

    vector result(30, vector(30, vector(105, -1.0)));;
    function<double(int, int, int)> compute = [&](const int i, const int j, const int m) {
      if (i < 0 or j < 0 or i >= n or j >= n) return 0.0;
      if (m == 0) return 1.0;
      if (result[i][j][m] > -0.9) return result[i][j][m];

      return result[i][j][m] = (compute(i + 1, j + 2, m - 1)
        + compute(i + 2, j + 1, m - 1)
        + compute(i + 1, j - 2, m - 1)
        + compute(i + 2, j - 1, m - 1)
        + compute(i - 1, j + 2, m - 1)
        + compute(i - 2, j + 1, m - 1)
        + compute(i - 1, j - 2, m - 1)
        + compute(i - 2, j - 1, m - 1)
      ) / 8;
    };

    return compute(row, column, k);
  }

  double knightProbability(int n, int k, int row, int column) {
    vector result(k + 1, vector(n, vector(n, 0.0)));
    for (int i = 0; i < n; ++i) { for (int j = 0; j < n; ++j) { result[0][i][j] = 1; } }
    const vector dirs = { -2, -1, 2, 1, -2, 1, 2, -1, -2 };
    for (int h = 1; h <= k; ++h) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          for (int p = 0; p < 8; ++p) {
            if (const int x = i + dirs[p], y = j + dirs[p + 1]; x >= 0 and x < n and y >= 0 and y < n) {
              result[h][i][j] += result[h - 1][x][y] / 8;
            }
          }
        }
      }
    }
    return result[k][row][column];
  }
};
