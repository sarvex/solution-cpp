#include <cstdint>
#include <stack>
#include <vector>

class Solution {
public:
  auto maximumScore(const std::vector<int>& nums, const int k) {
    const auto n = nums.size();
    std::vector left(n, -1);
    std::vector right(n, n);
    std::stack<int> stk;
    for (int i = 0; i < n; ++i) {
      const int v = nums[i];
      while (not stk.empty() and nums[stk.top()] >= v) stk.pop();
      if (not stk.empty()) left[i] = stk.top();
      stk.push(i);
    }
    stk = std::stack<int>();
    for (int i = n - 1; i >= 0; --i) {
      const int v = nums[i];
      while (not stk.empty() and nums[stk.top()] > v) stk.pop();
      if (not stk.empty()) right[i] = stk.top();
      stk.push(i);
    }
    uint64_t result = 0;
    for (int i = 0; i < n; ++i) {
      if (left[i] + 1 <= k and k <= right[i] - 1) result = std::max(result, nums[i] * (right[i] - left[i] - 1));
    }
    return static_cast<int>(result);
  }
};
