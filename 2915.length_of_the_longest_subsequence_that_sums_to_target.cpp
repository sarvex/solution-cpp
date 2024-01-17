#include <limits>
#include <vector>

class Solution {
public:
  int lengthOfLongestSubsequence(const std::vector<int>& nums, const int target) {
    std::vector f(target + 1, std::numeric_limits<int>::min());
    f[0] = 0;
    for (int x: nums) for (int j = target; j >= x; --j) f[j] = max(f[j], f[j - x] + 1);
    return f[target] <= 0 ? -1 : f[target];
  }
};
