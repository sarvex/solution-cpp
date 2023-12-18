#include <algorithm>
#include <limits>
#include <vector>

class Solution {
public:
  int maxProductDifferenceFast(const std::vector<int>& nums) {
    int max1 = std::numeric_limits<int>::min();
    int max2 = std::numeric_limits<int>::min();
    int min1 = std::numeric_limits<int>::max();
    int min2 = std::numeric_limits<int>::max();

    for (auto & num : nums) {
      if (num > max1) {
        max2 = max1;
        max1 = num;
      } else {
        max2 = std::max(num, max2);
      }
      if (num < min1) {
        min2 = min1;
        min1 = num;
      } else {
        min2 = std::min(num, min2);
      }
    }

    return max1 * max2 - min1 * min2;
  }

  int maxProductDifference(std::vector<int>& nums) {
    const auto n = nums.size();
    std::partial_sort(nums.rbegin(), nums.rbegin() + 2, nums.rend(), std::greater{});
    int result = nums[n-1] * nums[n-2];
    std::partial_sort(nums.begin(), nums.begin() + 2, nums.end());
    result -= (nums[1] * nums[0]);
    return result;
  }
};
