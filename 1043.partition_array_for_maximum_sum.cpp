#include <vector>

class Solution {
public:
  int maxSumAfterPartitioning(const std::vector<int>& arr, int k) {
    const auto n = arr.size();
    std::vector f(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      int mx = 0;
      const int idx = std::max(0, i - k);
      for (int j = i; j > idx; --j) {
        mx = std::max(mx, arr[j - 1]);
        f[i] = std::max(f[i], f[j - 1] + mx * (i - j + 1));
      }
    }
    return f[n];
  }
};
