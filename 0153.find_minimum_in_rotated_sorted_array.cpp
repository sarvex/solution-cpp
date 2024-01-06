#include <vector>

class Solution {
public:
  int findMin(std::vector<int>& nums) {
    const int n = nums.size();
    if (nums[0] <= nums[n - 1]) return nums[0];
    int left = 0, right = n - 1;
    while (left < right) {
      if (const int mid = left + ((right - left) >> 1); nums[0] <= nums[mid])
        left = mid + 1;
      else
        right = mid;
    }
    return nums[left];
  }
};
