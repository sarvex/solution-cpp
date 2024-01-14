#include <functional>
#include <vector>

class Solution {
public:
  auto maximumJumps(const std::vector<int>& nums, const int target) {
    const auto n = nums.size();
    std::vector f(n, -1);
    std::function<int(int)> search = [&](const int i) {
      if (i == n - 1) return 0;
      if (f[i] != -1) return f[i];
      f[i] = -(1 << 30);
      for (int j = i + 1; j < n; ++j) if (abs(nums[i] - nums[j]) <= target) f[i] = max(f[i], 1 + search(j));
      return f[i];
    };
    return std::max(search(0), -1);
  }
};
