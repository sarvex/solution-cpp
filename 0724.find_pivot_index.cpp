#include <numeric>
#include <vector>

class Solution {
public:
  int pivotIndex(std::vector<int>& nums) {
    int left = 0, right = reduce(nums.cbegin(), nums.cend());
    for (int i = 0; i < nums.size(); ++i) {
      right -= nums[i];
      if (left == right) return i;
      left += nums[i];
    }
    return -1;
  }
};
