#include <unordered_map>
#include <vector>

class Solution {
public:
  auto twoSum(const std::vector<int> &nums, const int target)
      -> std::vector<int> {
    std::unordered_map<int, int> map;

    for (auto i = 0;; ++i) {
      auto x = nums[i];

      if (auto search = map.find(target - x); search != map.end())
        return {search->second, i};
      map.emplace(x, i);
    }
  }
};
