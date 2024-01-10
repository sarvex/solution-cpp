#include <vector>

class Solution {
public:
  int longestOnes(const std::vector<int>& nums, int k) {
    const int n = nums.size();
    int left = 0, right = 0;
    while (right < n) {
      if (nums[right++] == 0) --k;
      if (k < 0 and nums[left++] == 0) ++k;
    }
    return right - left;
  }
};
