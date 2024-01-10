#include <cstdint>
#include <unordered_map>
#include <vector>

class Solution {
public:
  int numberOfArithmeticSlices(const std::vector<int>& nums) {
    const int n = nums.size();
    std::unordered_map<int64_t, int> f[n];
    int result = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        int64_t d = 1LL * nums[i] - nums[j];
        const int cnt = f[j][d];
        result += cnt;
        f[i][d] += cnt + 1;
      }
    }
    return result;
  }
};
