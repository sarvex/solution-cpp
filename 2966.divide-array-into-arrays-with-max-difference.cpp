#include <algorithm>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> divideArray(std::vector<int>& nums, const int k) {
    std::ranges::sort(nums);
    std::vector<std::vector<int>> result;
    const auto n = nums.size();
    for (int i = 0; i < n; i += 3) {
      std::vector t = {nums[i], nums[i + 1], nums[i + 2]};
      if (t[2] - t[0] > k) {
        return {};
      }
      result.emplace_back(t);
    }
    return result;
  }
};