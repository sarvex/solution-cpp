#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
public:
  double findMaxAverage(const std::vector<int>& nums, const int k) {
    const int n = nums.size();
    int result = std::reduce(nums.cbegin(), nums.cbegin() + k);
    int sum = result;
    for (int i = k; i < n; ++i) {
      sum += (nums[i] - nums[i - k]);
      result = std::max(result, sum);
    }
    return result * 1.0 / k;
  }
};
