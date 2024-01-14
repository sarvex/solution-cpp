#include <cstdint>
#include <limits>
#include <unordered_set>
#include <vector>

class Solution {
public:
  auto minimumIncompatibility(const std::vector<int>& nums, const int k) {
    const int n = static_cast<int>(nums.size()), m = n / k, size = 1 << n;
    std::vector g(size, -1);
    for (size_t i = 1; i < size; ++i) {
      if (std::popcount(i) != m) { continue; }
      std::unordered_set<int> s;
      int mi = 20, mx = 0;
      for (int j = 0; j < n; ++j) {
        if (i >> j & 1) {
          if (s.contains(nums[j])) { break; }
          s.insert(nums[j]);
          mi = std::min(mi, nums[j]);
          mx = std::max(mx, nums[j]);
        }
      }
      if (s.size() == m) { g[i] = mx - mi; }
    }
    constexpr auto inf = std::numeric_limits<int>::max() >> 2;
    std::vector f(size, inf);
    f[0] = 0;
    for (int i = 0; i < 1 << n; ++i) {
      if (f[i] == inf) continue;
      std::unordered_set<int> s;
      int mask = 0;
      for (int j = 0; j < n; ++j) {
        if ((i >> j & 1) == 0 and not s.contains(nums[j])) {
          s.insert(nums[j]);
          mask |= 1 << j;
        }
      }
      if (s.size() < m) { continue; }
      for (int j = mask; j; j = (j - 1) & mask) { if (g[j] != -1) { f[i | j] = std::min(f[i | j], f[i] + g[j]); } }
    }
    return f[(1 << n) - 1] == inf ? -1 : f[(1 << n) - 1];
  }
};
