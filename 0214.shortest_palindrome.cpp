#include <algorithm>
#include <cstdint>
#include <string>

class Solution {
public:
  auto shortestPalindrome(std::string& s) {
    constexpr auto base = 131;
    const int n = static_cast<int>(s.size());
    uint64_t mul = 1, prefix = 0, suffix = 0;
    int idx = 0;
    for (int i = 0; i < n; ++i) {
      const auto t = s[i] - 'a' + 1;
      prefix = prefix * base + t;
      suffix = suffix + mul * t;
      mul *= base;
      if (prefix == suffix) idx = i + 1;
    }
    if (idx == n) return s;
    std::string x = s.substr(idx, n - idx);
    std::ranges::reverse(x);
    return x + s;
  }
};
