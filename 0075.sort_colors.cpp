#include <algorithm>
#include <vector>

using std::vector;
using std::swap;

class Solution {
public:
  auto sortColors(vector<int>& nums) {
    int i = -1, j = nums.size(), k = 0;
    while (k < j) {
      if (nums[k] == 0) {
        swap(nums[++i], nums[k++]);
      } else if (nums[k] == 2) {
        swap(nums[--j], nums[k]);
      } else {
        ++k;
      }
    }
  }
};
