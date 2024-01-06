#include <vector>

class Solution {
public:
  int maxSubarraySumCircular(std::vector<int>& nums) {
    int s1 = nums[0], s2 = nums[0], f1 = nums[0], f2 = nums[0], total = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      total += nums[i];
      f1 = nums[i] + std::max(f1, 0);
      f2 = nums[i] + std::min(f2, 0);
      s1 = std::max(s1, f1);
      s2 = std::min(s2, f2);
    }
    return s1 > 0 ? std::max(s1, total - s2) : s1;
  }
};
