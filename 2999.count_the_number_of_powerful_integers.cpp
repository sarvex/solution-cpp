#include <cstdint>
#include <functional>
#include <string>
#include <vector>

class Solution {
public:
  int64_t numberOfPowerfulInt(const int64_t start, const int64_t finish, const int limit, const std::string& s) {
    std::string t = std::to_string(start - 1);
    std::vector f(20, -1LL);

    const std::function<int64_t(int, bool)> search = [&](const int pos, const bool lim) -> int64_t {
      if (t.size() < s.size()) return 0;
      if (not lim and f[pos] != -1) return f[pos];
      if (t.size() - pos == s.size()) return lim ? s <= t.substr(pos) : 1;
      int64_t result = 0;
      const int up = std::min(lim ? t[pos] - '0' : 9, limit);
      for (int i = 0; i <= up; ++i) result += search(pos + 1, lim && i == (t[pos] - '0'));
      if (not lim) { f[pos] = result; }
      return result;
    };

    const int64_t a = search(0, true);
    t = std::to_string(finish);
    f.assign(f.size(), -1LL);
    const int64_t b = search(0, true);
    return b - a;
  }
};
