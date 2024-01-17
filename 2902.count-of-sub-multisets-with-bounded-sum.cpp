#include <algorithm>
#include <cstdint>
#include <map>
#include <vector>

class Solution {
public:
  int countSubMultisets(const std::vector<int>& nums, const int l, const int r) {
    constexpr int64_t mod = 1e9 + 7;
    constexpr int64_t n = 2e4;
    std::vector<int64_t> dp(n + 1);
    std::map<int64_t,int64_t> m;
    dp[0] = 1;
    m[0] = 1;
    for(auto x : nums) m[x]++;

    const int64_t mult = m[0]; m.erase(0);
    for(auto [a, c] : m) {
      std::vector<int64_t> help(n + 1);
      for(int i = 1; i <= n; i++) {
        int64_t sum = 0;
        if(i - a >= 0) {
          sum += dp[i-a];
          sum += help[i-a];
        }
        if(i - a * (c + 1) >= 0) sum -= dp[i - a * (c + 1)];
        help[i] = (sum + mod) % mod;
      }
      for(int i = 0; i <= n; i++) {
        dp[i] += help[i];
        if(dp[i] >= mod) dp[i] -= mod;
      }
    }
    int64_t sum = 0;
    for(int i = l; i <= r; i++) {
      sum += dp[i];
      if(sum >= mod) sum -= mod;
    }
    return static_cast<int>(sum * mult % mod);
  }
};
