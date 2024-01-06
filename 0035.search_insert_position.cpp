#include <vector>

class Solution {
public:
  auto searchInsert(const std::vector<int>& nums, const int target) {
    int left = 0, right = nums.size();
    while (left < right) {
      if (const int mid = left + (right - left) >> 1; nums[mid] >= target)
        right = mid;
      else
        left = mid + 1;
    }
    return left;
  }
};
