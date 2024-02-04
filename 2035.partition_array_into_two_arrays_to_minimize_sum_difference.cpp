#include <algorithm>
#include <vector>

class Solution {
public:
  auto minimumDifference(const std::vector<int>& nums) {
    const auto n = nums.size() >> 1;
    std::vector<std::vector<int>> f(n + 1), g(n + 1);
    for (int i = 0; i < (1 << n); ++i) {
      int s = 0, cnt = 0;
      int s1 = 0, cnt1 = 0;
      for (int j = 0; j < n; ++j) {
        if (i & (1 << j)) {
          s += nums[j];
          ++cnt;
          s1 += nums[n + j];
          ++cnt1;
        } else {
          s -= nums[j];
          s1 -= nums[n + j];
        }
      }
      f[cnt].push_back(s);
      g[cnt1].push_back(s1);
    }
    for (int i = 0; i <= n; ++i) {
      std::ranges::sort(f[i]);
      std::ranges::sort(g[i]);
    }
    int ans = std::numeric_limits<int>::max();
    for (int i = 0; i <= n; ++i) {
      for (const auto a: f[i]) {
        int left = 0, right = g[n - i].size() - 1;
        const int b = -a;
        while (left < right) {
          if (const int mid = (left + right) >> 1; g[n - i][mid] >= b) right = mid;
          else left = mid + 1;
        }
        ans = std::min(ans, abs(a + g[n - i][left]));
        if (left > 0) ans = std::min(ans, abs(a + g[n - i][left - 1]));
      }
    }
    return ans;
  }
};
