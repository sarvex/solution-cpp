#include <unordered_map>
#include <vector>

class Solution {
public:
  static std::vector<int> twoSum(const std::vector<int> &nums, const int target) {
    std::unordered_map<int, int> map;
    for (auto i = 0;; ++i) {
      auto x = nums[i];
      if (int y = target - x; map.contains(y)) {
        return {map[y], i};
      }
      map[x] = i;
    }
  }
};
