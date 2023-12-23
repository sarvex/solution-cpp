#include <cstdint>
#include <vector>

class Solution {
public:
  int minSubArrayLen(int target, std::vector<int>& nums) {
    const int n = nums.size();
    int result = n + 1;
    int64_t s = 0;
    for (int i = 0, j = 0; i < n; ++i) {
      s += nums[i];
      while (j < n and s >= target) {
        result = std::min(result, i - j + 1);
        s -= nums[j++];
      }
    }
    return result == n + 1 ? 0 : result;
  }
};
