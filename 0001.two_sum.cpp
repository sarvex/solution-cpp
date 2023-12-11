#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

class Solution {
public:
  auto twoSum(const vector<int>& nums, const int target) -> vector<int> {
    unordered_map<int, int> map;

    for (auto i = 0;; ++i) {
      auto x = nums[i];

      if (auto search = map.find(target - x); search != map.end()) return { search->second, i };
      map.emplace(x, i);
    }
  }
};
