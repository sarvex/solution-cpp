#include <algorithm>
#include <vector>

class Solution {
public:
  auto maxSubArray(const std::vector<int> &nums) {
    const int n = nums.size();
    int result = nums[0], sum = nums[0];
    for (int i = 1; i < n; ++i) {
      sum = std::max(sum, 0) + nums[i];
      result = std::max(result, sum);
    }
    return result;
  }
};
