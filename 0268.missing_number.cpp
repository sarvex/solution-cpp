#include <__numeric/reduce.h>
#include <vector>

class Solution {
public:
  auto missingNumber(const std::vector<int>& nums) {
    const auto n = nums.size();
    return n * (n + 1) / 2 - std::reduce(nums.cbegin(), nums.cend(), 0);
  }

  auto missingNumber(const std::vector<int>& nums) {
    const auto n = nums.size();
    int result = n;
    for (int i = 0; i < n; ++i) result ^= (i ^ nums[i]);
    return result;
  }
};
