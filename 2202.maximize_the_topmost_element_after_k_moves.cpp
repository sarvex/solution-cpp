#include <algorithm>
#include <vector>

class Solution {
public:
  auto maximumTop(std::vector<int>& nums, int k) {
    if (k == 0) return nums[0];
    const int n = static_cast<int>(nums.size());
    if (n == 1) {
      if (k % 2) return -1;
      return nums[0];
    }
    int result = -1;
    const int m = std::min(k - 1, n);
    for (int i = 0; i < n; ++i) result = std::max(result, nums[i]);
    if (k < n) result = std::max(result, nums[k]);
    return result;
  }
};
