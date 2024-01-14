#include <cstdint>
#include <functional>
#include <string>
#include <vector>

class Solution {
public:
  int numberOfWays(const std::string& corridor) {
    constexpr int MOD = 1'000'000'007;
    int64_t seats = 0, plants = 0, ways = 1;
    for (auto& ch: corridor) {
      switch (ch) {
        case 'S': if (seats == 2) {
            seats = 1;
            ways = ways * (plants + 1) % MOD;
            plants = 0;
          } else ++seats;
          break;
        case 'P': if (seats == 2) ++plants;
          break;
        default: break;
      }
    }

    return (seats == 2) ? static_cast<int>(ways) : 0;
  }

  auto numberOfWays(const std::string& corridor) {
    constexpr int mod = 1e9 + 7;
    const auto n = corridor.size();
    std::vector dp(n, std::vector(3, -1));

    const std::function<int(int, int)> dfs = [&](const int i, int cnt) {
      if (i == n) return cnt == 2 ? 1 : 0;
      cnt += corridor[i] == 'S';
      if (cnt > 2) return 0;
      if (dp[i][cnt] != -1) return dp[i][cnt];
      int result = dfs(i + 1, cnt);
      if (cnt == 2) {
        result += dfs(i + 1, 0);
        result %= mod;
      }
      dp[i][cnt] = result;
      return result;
    };
    return dfs(0, 0);
  }
};
