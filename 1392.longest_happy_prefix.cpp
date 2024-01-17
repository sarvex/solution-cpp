#include <cstdint>
#include <string>
#include <vector>

class Solution {
public:
  std::string longestPrefix(const std::string& s) {
    const auto n = s.size();
    std::vector nexts(n, 0);
    int pre = 0, i = 1;
    while (i < n)
      if (s[i] == s[pre]) {
        pre++;
        nexts[i] = pre;
        ++i;
      } else if (pre == 0) ++i;
      else pre = nexts[pre - 1];
    return s.substr(0, nexts.back());
  }

  auto longestPrefix(const std::string& s) {
    constexpr int base = 131;
    const auto n = s.size();
    std::vector p(n + 10, 0ULL);
    std::vector h(n + 10, 0ULL);
    p[0] = 1;
    h[0] = 0;
    for (int i = 0; i < n; ++i) {
      p[i + 1] = p[i] * base;
      h[i + 1] = h[i] * base + s[i];
    }
    for (int l = n - 1; l > 0; --l) {
      const uint64_t prefix = h[l];
      const uint64_t suffix = h[n] - h[n - l] * p[l];
      if (prefix == suffix) return s.substr(0, l);
    }
    return "";
  }
};
