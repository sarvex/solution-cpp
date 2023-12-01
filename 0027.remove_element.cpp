#include <vector>

class Solution {
public:
  static int removeElement(std::vector<int>& nums, const int val) {
    auto k = 0;
    for (const auto x: nums) {
      if (x != val) {
        nums[k++] = x;
      }
    }
    return k;
  }
};
