#include <vector>

using std::vector;

class Solution {
public:
  auto searchInsert(const vector<int>& nums, const int target) {
    int left = 0, right = nums.size();
    while (left < right) {
      int mid = (left + right) >> 1;
      if (nums[mid] >= target)
        right = mid;
      else
        left = mid + 1;
    }
    return left;
  }
};
