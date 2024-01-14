#include <string>
#include <vector>

class Solution {
public:
  auto beautifulPartitions(const std::string& s, const int k, const int minLength) {
    constexpr int mod = 1e9 + 7;
    const auto n = s.size();
    auto prime = [](const char c) { return c == '2' or c == '3' or c == '5' or c == '7'; };
    if (not prime(s[0]) or prime(s[n - 1])) return 0;

    std::vector result(n + 1, std::vector(k + 1, 0));
    std::vector previous(n + 1, std::vector(k + 1, 0));
    result[0][0] = previous[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
      if (i >= minLength and not prime(s[i - 1]) and (i == n or prime(s[i])))
        for (int j = 1; j <= k; ++j) result[i][j] = previous[i - minLength][j - 1];
      for (int j = 0; j <= k; ++j) previous[i][j] = (previous[i - 1][j] + result[i][j]) % mod;
    }
    return result[n][k];
  }
};
