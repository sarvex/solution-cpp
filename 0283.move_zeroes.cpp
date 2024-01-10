#include <vector>

class Solution {
public:
  void moveZeroes(std::vector<int>& nums) {
    const int n = nums.size();
    for (int j = 0, i = -1; j < n; ++j) { if (nums[j]) { std::swap(nums[++i], nums[j]); } }
  }
};
