#include <algorithm>
#include <vector>

class Solution {
public:
  auto minOperations(std::vector<int>& nums) {
    sort(nums.begin(), nums.end());
    const auto m = unique(nums.begin(), nums.end()) - nums.begin();
    const auto n = nums.size();
    int result = static_cast<int>(n);
    for (int i = 0, j = 0; i < m; ++i) {
      while (j < m and nums[j] - nums[i] <= n - 1) { ++j; }
      result = std::min(result, static_cast<int>(n) - (j - i));
    }
    return result;
  }
};
