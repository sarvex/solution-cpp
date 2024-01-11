#include <functional>
#include <string>
#include <vector>

class Solution {
public:
  auto solveNQueens(int n) {
    std::vector<int> col(n);
    std::vector<int> dg(n << 1);
    std::vector<int> udg(n << 1);
    std::vector<std::vector<std::string>> result;
    std::vector t(n, std::string(n, '.'));
    const std::function<void(int)> search = [&](const int i) -> void {
      if (i == n) {
        result.emplace_back(t);
        return;
      }
      for (int j = 0; j < n; ++j) {
        if (col[j] + dg[i + j] + udg[n - i + j] == 0) {
          t[i][j] = 'Q';
          col[j] = dg[i + j] = udg[n - i + j] = 1;
          search(i + 1);
          col[j] = dg[i + j] = udg[n - i + j] = 0;
          t[i][j] = '.';
        }
      }
    };
    search(0);
    return result;
  }
};
