#include <functional>
#include <vector>

class Solution {
public:
  int removeBoxesFast (const std::vector<int>& boxes) {
    const auto n = boxes.size();

    std::vector p(105, 0);
    std::vector result(105, std::vector(105, 0));
    std::vector sums(105, 0);

    for (int i = 0; i < n; ++i) { result[i][i] = 1; }
    for (int r = 0; r < n; ++r) {
      for (int l = r - 1; l >= 0; --l) {
        for (int k = l; k < r; ++k) { result[l][r] = std::max(result[l][r], result[l][k] + result[k + 1][r]); }
        if (boxes[l] == boxes[r]) {
          int z = 0;
          p[z++] = l - 1;
          for (int k = l; k <= r; ++k) { if (boxes[k] == boxes[l]) { p[z++] = k; } }
          int& value = result[l][r];
          p[z++] = r + 1;
          sums[z - 1] = 0;

          for (int i = z - 2; i >= 1; --i) {
            const int a = p[i] + 1;
            const int b = p[i + 1] - 1;
            sums[i] = sums[i + 1] + (a <= b ? result[a][b] : 0);
          }
          int p_sum = 0;
          for (int i = 1; i < z; ++i) {
            const int a = p[i] + 1;
            if (a >= 2) { p_sum += result[p[i - 1] + 1][a - 2]; }
            for (int j = z - 2; j >= i + 1 && (z - 2 - j <= 2); --j) {
              const int b = p[j] - 1;
              const int cnt = i + (z - j - 1);
              const int cur = cnt * cnt + p_sum + sums[j] + result[a][b];
              value = std::max(value, cur);
            }
          }
        }
      }
    }
    return result[0][n - 1];
  }

  auto removeBoxes(const std::vector<int>& boxes) {
    const auto n = static_cast<int>(boxes.size());
    std::vector f(n, std::vector(n, std::vector(n, 0)));
    std::function<int(int, int, int)> search;
    search = [&](int i, int j, int k) {
      if (i > j) return 0;
      while (i < j and boxes[j] == boxes[j - 1]) {
        --j;
        ++k;
      }
      if (f[i][j][k]) return f[i][j][k];
      int ans = search(i, j - 1, 0) + (k + 1) * (k + 1);
      for (int h = i; h < j; ++h) {
        if (boxes[h] == boxes[j]) ans = std::max(ans, search(h + 1, j - 1, 0) + search(i, h, k + 1));
      }
      f[i][j][k] = ans;
      return ans;
    };
    return search(0, n - 1, 0);
  }
};
