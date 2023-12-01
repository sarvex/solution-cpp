#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

class Solution {
public:
  static auto twoSum(const vector<int> &nums, const int target) -> vector<int> {
    unordered_map<int, int> map;

    for (auto i = 0;; ++i) {
      auto x = nums[i];

      if (auto search = map.find(target - x); search != map.end())
        return {search->second, i};
      else
        map.emplace(x, i);
    }
  }
};
