#include <vector>

class Solution {
public:
  std::vector<int> sortArrayByParityII(std::vector<int>& nums) {
    const int n = nums.size();
    for (int i = 0, j = 1; i < n; i += 2) {
      if (nums[i] & 1) {
        while (nums[j] & 1) j += 2;
        std::swap(nums[i], nums[j]);
      }
    }
    return nums;
  }
};
