#include <string>
#include <vector>

class Solution {
public:
  std::vector<std::string> summaryRanges(const std::vector<int>& nums) {
    std::vector<std::string> result;
    auto range = [&](const int i, const int j) {
      return i == j ? std::to_string(nums[i]) : std::to_string(nums[i]) + "->" + std::to_string(nums[j]);
    };
    const int n = nums.size();
    for (int i = 0, j; i < n; i = j + 1) {
      j = i;
      while (j + 1 < n and nums[j + 1] == nums[j] + 1) { ++j; }
      result.emplace_back(range(i, j));
    }
    return result;
  }
};
