#include <limits>
#include <string>
#include <vector>

class Solution {
public:
  int getLengthOfOptimalCompression(const std::pmr::string& s, const int k) {
    const int n = s.size();
    std::vector result(n + 1, std::vector(k + 1, n - k));
    result[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
      const int m = std::min (i, k);
      for (int j = 0; j <= m; ++j) {
        if (j) result[i][j] = std::min(result[i][j], result[i - 1][j - 1]);
        int cnt = 0, del = 0;
        for (int t = i; t > 0; --t) {
          if (s[t - 1] == s[i - 1]) ++cnt;
          else ++del;
          if (j - del < 0) break;
          result[i][j] = std::min(result[i][j], result[t - 1][j - del] + (cnt >= 100 ? 4 : cnt >= 10 ? 3 : cnt >= 2 ? 2 : 1));
        }
      }
    }
    return result[n][k];
  }
};
