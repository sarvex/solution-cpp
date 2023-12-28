#include <algorithm>
#include <cmath>
#include <vector>

class Solution {
public:
  auto threeSumClosest(std::vector<int>& nums, const int target) {
    const int n = nums.size();
    std::sort(nums.begin(), nums.end());
    int result = nums[0] + nums[1] + nums[2];

    for (int i = 0; i < n - 2; i++) {
      if (i > 0 && nums[i] == nums[i - 1]) continue;
      const int min_sum = nums[i] + nums[i + 1] + nums[i + 2];
      const int max_sum = nums[i] + nums[n - 1] + nums[n - 2];

      if (min_sum >= target) {
        if (abs(min_sum - target) < abs(result - target)) return min_sum;
        return result;
      }
      if (max_sum < target) {
        if (abs(max_sum - target) < abs(result - target)) result = max_sum;
        continue;
      }
      int left = i + 1;
      int right = n - 1;

      while (left < right) {
        const int sum = nums[i] + nums[left] + nums[right];
        if (abs(sum - target) < abs(result - target)) result = sum;

        if (sum > target) { right--; } else if (sum < target) { left++; } else return target;
      }
    }
    return result;
  }
};
