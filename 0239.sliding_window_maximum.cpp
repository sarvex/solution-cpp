#include <deque>
#include <vector>

class Solution {
public:
  auto maxSlidingWindow(std::vector<int>& nums, const int k) {
    std::deque<int> q;
    std::vector<int> result;
    const auto n = nums.size();
    for (int i = 0; i < n; ++i) {
      if (not q.empty() and i - k + 1 > q.front()) q.pop_front();
      while (not q.empty() and nums[q.back()] <= nums[i]) q.pop_back();
      q.push_back(i);
      if (i >= k - 1) result.emplace_back(nums[q.front()]);
    }
    return result;
  }
};
