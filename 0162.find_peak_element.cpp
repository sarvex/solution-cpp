#include <vector>

class Solution {
public:
  int findPeakElementFastg(std::vector<int>& nums) {
    const int n = nums.size();
    if (n == 1) return 0;

    int left = 0;
    int right = n - 1;
    while (left <= right) {
      const int mid = left + ((right - left) >> 2);
      if ((mid == 0 and nums[mid] > nums[mid + 1]) or (mid == n - 1 and nums[mid] > nums[mid - 1]) or (
            mid > 0 and mid < n - 1 and nums[mid] > nums[mid + 1] and nums[mid] > nums[mid - 1]))
        return mid;
      if (mid > 0 and nums[mid] < nums[mid - 1]) {
        right = mid - 1;
      } else if (mid < n - 1 and nums[mid] < nums[mid + 1]) {
        left = mid + 1;
      }
    }
    return -1;
  }

  int findPeakElement(const std::vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
      if (const int mid = left + ((right - left) >> 1); nums[mid] > nums[mid + 1]) right = mid;
      else left = mid + 1;
    }
    return left;
  }
};
