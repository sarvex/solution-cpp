#include <string>
#include <vector>

class Solution {
  public:
    auto longestCommonSubsequence(const std::string& text1, const std::string& text2) {
      const auto m = text1.size(), n = text2.size();
      std::vector result(m + 1, std::vector(n + 1, 0));
      for (auto i = 1; i <= m; ++i) {
        for (auto j = 1; j <= n; ++j) {
          if (text1[i - 1] == text2[j - 1]) {
            result[i][j] = result[i - 1][j - 1] + 1;
          } else {
            result[i][j] = std::max(result[i - 1][j], result[i][j - 1]);
          }
        }
      }
      return result[m][n];
    }
};
