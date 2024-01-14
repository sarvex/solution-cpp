#include <deque>
#include <vector>

class Solution {
public:
  auto maxResult(const std::vector<int>& nums, const int k) {
    const auto n = nums.size();
    std::vector result(n, 0);
    std::deque q { 0 };
    for (int i = 0; i < n; ++i) {
      if (i - q.front() > k) q.pop_front();
      result[i] = nums[i] + result[q.front()];
      while (not q.empty() and result[q.back()] <= result[i]) q.pop_back();
      q.push_back(i);
    }
    return result[n - 1];
  }
};
