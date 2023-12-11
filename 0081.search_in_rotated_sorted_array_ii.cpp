#include <vector>

using std::vector;

class Solution {
public:
  auto search(vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
      int mid = (l + r) >> 1;
      if (nums[mid] > nums[r]) {
        if (nums[l] <= target and target <= nums[mid]) {
          r = mid;
        } else {
          l = mid + 1;
        }
      } else if (nums[mid] < nums[r]) {
        if (nums[mid] < target and target <= nums[r]) {
          l = mid + 1;
        } else {
          r = mid;
        }
      } else {
        --r;
      }
    }
    return nums[l] == target;
  }
};
