#include <cstdint>
#include <functional>
#include <string>
#include <unordered_map>

class Solution {
public:
  int maxPartitionsAfterOperations(const std::string& s, const int k) {
    const int n = s.size();
    std::unordered_map<int64_t, int> f;
    std::function<int(int, unsigned int, int)> search = [&](const int i, const unsigned int cur, const int t) {
      if (i >= n) { return 1; }
      const int64_t key = static_cast<int64_t>(i) << 32 | cur << 1 | t;
      if (f.contains(key)) { return f[key]; }
      const int v = 1 << (s[i] - 'a');
      unsigned int nxt = cur | v;
      int result = std::popcount(nxt) > k ? search(i + 1, v, t) + 1 : search(i + 1, nxt, t);
      if (t) {
        for (int j = 0; j < 26; ++j) {
          nxt = cur | (1 << j);
          if (std::popcount(nxt) > k) { result = std::max(result, search(i + 1, 1 << j, 0) + 1); } else {
            result = std::max(result, search(i + 1, nxt, 0));
          }
        }
      }
      return f[key] = result;
    };
    return search(0, 0, 1);
  }
};
