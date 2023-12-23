#include <unordered_map>
#include <vector>

class Solution {
public:
  bool containsNearbyDuplicate(const std::vector<int>& nums, const int k) {
    std::unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); ++i) {
      if (map.contains(nums[i]) and i - map[nums[i]] <= k) return true;
      map[nums[i]] = i;
    }
    return false;
  }
};
