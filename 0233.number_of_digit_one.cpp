#include <functional>
#include <vector>

class Solution {
public:
  int countDigitOne(int n) {
    std::vector a(12, 0);
    std::vector dp(12, std::vector(12, -1));

    std::function<int(int, int, bool)> count = [&](const int pos, const int cnt, const bool limit) {
      if (pos <= 0) { return cnt; }
      if (not limit and dp[pos][cnt] != -1) { return dp[pos][cnt]; }
      int ans = 0;
      const int up = limit ? a[pos] : 9;
      for (int i = 0; i <= up; ++i) { ans += count(pos - 1, cnt + (i == 1), limit and i == up); }
      if (! limit) { dp[pos][cnt] = ans; }
      return ans;
    };

    int len = 0;
    while (n) {
      a[++len] = n % 10;
      n /= 10;
    }
    return count(len, 0, true);
  }
};
