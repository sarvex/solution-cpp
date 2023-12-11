#include <vector>

using std::vector;

class Solution {
public:
  auto search(vector<int> &nums, int target) {
    int n = nums.size();
    int left = 0, right = n - 1;
    while (left < right) {
      int mid = (left + right) >> 1;
      if (nums[0] <= nums[mid]) {
        if (nums[0] <= target and target <= nums[mid])
          right = mid;
        else
          left = mid + 1;
      } else {
        if (nums[mid] < target and target <= nums[n - 1])
          left = mid + 1;
        else
          right = mid;
      }
    }
    return nums[left] == target ? left : -1;
  }
};
