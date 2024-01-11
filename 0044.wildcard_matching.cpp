#include <string>
#include <vector>

class Solution {
public:
  auto isMatch(const std::string& s, const std::string& p) {
    const int m = s.size(), n = p.size();
    std::vector result(m + 1, std::vector<bool>(n + 1));
    result[0][0] = true;
    for (int j = 1; j <= n; ++j) { if (p[j - 1] == '*') { result[0][j] = result[0][j - 1]; } }
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (s[i - 1] == p[j - 1] or p[j - 1] == '?') {
          result[i][j] = result[i - 1][j - 1];
        } else if (
          p[j - 1] == '*') { result[i][j] = result[i - 1][j] or result[i][j - 1]; }
      }
    }
    return result[m][n];
  }
};
