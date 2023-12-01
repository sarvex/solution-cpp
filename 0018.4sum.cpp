#include <algorithm>
#include <vector>

class Solution {
public:
  static std::vector<std::vector<int>> fourSum(std::vector<int> &nums, const int target) {
    const int n = nums.size();
    std::vector<std::vector<int>> result;
    if (n < 4) {
      return result;
    }
    std::ranges::sort(nums);
    for (auto i = 0; i < n - 3; ++i) {
      if (i and nums[i] == nums[i - 1]) {
        continue;
      }
      for (int j = i + 1; j < n - 2; ++j) {
        if (j > i + 1 and nums[j] == nums[j - 1]) {
          continue;
        }
        int k = j + 1, l = n - 1;
        while (k < l) {
          if (const auto x = static_cast<long long>(nums[i]) + nums[j] + nums[k] + nums[l]; x < target) {
            ++k;
          } else if (x > target) {
            --l;
          } else {
            result.push_back({nums[i], nums[j], nums[k++], nums[l--]});
            while (k < l and nums[k] == nums[k - 1]) {
              ++k;
            }
            while (k < l and nums[l] == nums[l + 1]) {
              --l;
            }
          }
        }
      }
    }
    return result;
  }
};