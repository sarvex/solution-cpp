#include <vector>

class Solution {
public:
  auto getMaxLen(const std::vector<int>& nums) {
    int f1 = nums[0] > 0 ? 1 : 0;
    int f2 = nums[0] < 0 ? 1 : 0;
    int result = f1;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] > 0) {
        ++f1;
        f2 = f2 > 0 ? f2 + 1 : 0;
      } else if (nums[i] < 0) {
        const int pf1 = f1, pf2 = f2;
        f2 = pf1 + 1;
        f1 = pf2 > 0 ? pf2 + 1 : 0;
      } else {
        f1 = 0;
        f2 = 0;
      }
      result = std::max(result, f1);
    }
    return result;
  }
};
