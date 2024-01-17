#include <functional>
#include <limits>
#include <string>
#include <vector>

class Solution {
public:
  auto strangePrinterFast(const std::string& s) {
    const auto n = static_cast<int>(s.size());
    std::vector table(n, std::vector(n, 0));

    const std::function<int(int, int)> calculate = [&](int l, int r) {
      if (l > r) return 0;
      if (l == r) return 1;
      if (table[l][r] > 0) return table[l][r];
      int lprev = l;
      while (l + 1 <= r && s[l] == s[l + 1]) l++;
      int ans = 1 + calculate(l + 1, r);
      for (int i = l + 1; i <= r; i++)
        if (s[i] == s[l]) ans = std::min(ans, calculate(l + 1, i - 1) + calculate(i, r));
      return table[lprev][r] = ans;
    };

    return calculate(0, n - 1);
  }

  int strangePrinter(const std::string& s) {
    const auto n = static_cast<int>(s.size());
    std::vector f(n, std::vector(n, std::numeric_limits<int>::max()));
    for (int i = n - 1; ~i; --i) {
      f[i][i] = 1;
      for (int j = i + 1; j < n; ++j) {
        if (s[i] == s[j]) { f[i][j] = f[i][j - 1]; } else {
          for (int k = i; k < j; ++k) f[i][j] = std::min(f[i][j], f[i][k] + f[k + 1][j]);
        }
      }
    }
    return f[0][n - 1];
  }
};
