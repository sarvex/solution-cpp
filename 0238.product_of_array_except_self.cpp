#include <vector>

class Solution {
public:
  auto productExceptSelf(const std::vector<int>& nums) {
    const int n = nums.size();
    std::vector result(n, 0);
    for (int i = 0, left = 1; i < n; ++i) {
      result[i] = left;
      left *= nums[i];
    }
    for (int i = n - 1, right = 1; ~i; --i) {
      result[i] *= right;
      right *= nums[i];
    }
    return result;
  }
};
