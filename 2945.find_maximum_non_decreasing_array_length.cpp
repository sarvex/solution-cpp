#include <vector>

class Solution {
public:
  int findMaximumLength(const std::pmr::vector<int>& nums) {
    const int n = nums.size();
    std::vector result(n + 1, 0);
    std::vector pre(n + 2, 0);
    std::vector sum(n + 1, 0LL);
    for (int i = 0; i < n; ++i) {
      sum[i + 1] = sum[i] + nums[i];
    }
    for (int i = 1; i <= n; ++i) {
      pre[i] = std::max(pre[i], pre[i - 1]);
      result[i] = result[pre[i]] + 1;
      const auto j = lower_bound(sum.cbegin(), sum.cend(), sum[i] * 2 - sum[pre[i]]) - sum.cbegin();
      pre[j] = i;
    }
    return result[n];
  }
};
