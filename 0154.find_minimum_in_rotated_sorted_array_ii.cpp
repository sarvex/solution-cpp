#include <vector>

class Solution {
public:
  auto findMin(const std::vector<int>& nums) {
    int left = 0, right = static_cast<int>(nums.size() - 1);
    while (left < right) {
      if (const int mid = left + (right - left >> 1); nums[mid] > nums[right]) left = mid + 1;
      else if (nums[mid] < nums[right]) right = mid;
      else --right;
    }
    return nums[left];
  }
};
