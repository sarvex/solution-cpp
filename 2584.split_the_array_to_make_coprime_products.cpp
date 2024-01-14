#include <numeric>
#include <unordered_map>
#include <vector>

class Solution {
public:
  int findValidSplit(const std::vector<int>& nums) {
    std::unordered_map<int, int> first;
    const int n = static_cast<int>(nums.size());
    std::vector<int> last(n);
    iota(last.begin(), last.end(), 0);
    for (int i = 0; i < n; ++i) {
      int x = nums[i];
      for (int j = 2; j <= x / j; ++j) {
        if (x % j == 0) {
          if (first.contains(j)) { last[first[j]] = i; } else { first[j] = i; }
          while (x % j == 0) { x /= j; }
        }
      }
      if (x > 1) { if (first.contains(x)) { last[first[x]] = i; } else { first[x] = i; } }
    }
    int mx = last[0];
    for (int i = 0; i < n; ++i) {
      if (mx < i) { return mx; }
      mx = std::max(mx, last[i]);
    }
    return -1;
  }
};
