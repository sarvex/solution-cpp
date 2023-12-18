#include <numeric>
#include <vector>

using std::midpoint;
using std::vector;

class Solution {
public:
  auto search(const vector<int> &nums, int target) {
    const int n = nums.size();
    int left = 0, right = n - 1;
    while (left <= right) {
      const int mid = midpoint(left, right);
      if (nums[mid] == target) return mid;
      if (nums[left] <= nums[mid]) {
        if (nums[left] <= target and target <= nums[mid]) {
          right = mid - 1;
        } else {
          left = mid + 1;
        }
      } else {
        if (nums[mid] <= target and target <= nums[right]) {
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      }
    }
    return -1;
  }
};
