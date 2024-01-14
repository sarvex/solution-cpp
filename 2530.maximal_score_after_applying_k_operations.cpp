#include <cstdint>
#include <queue>

class Solution {
public:
  auto maxKelements(const std::vector<int>& nums, const int k) {
    std::priority_queue que(nums.begin(), nums.end());
    int64_t result = 0;
    for (int i = k; i; --i) {
      const int value = que.top();
      que.pop();
      result += value;
      que.push((value + 2) / 3);
    }
    return result;
  }
};
