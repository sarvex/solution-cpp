#include <set>
#include <vector>

class Solution {
public:
  bool containsNearbyAlmostDuplicate(const std::vector<int>& nums, const int indexDiff, const int valueDiff) {
    std::set<long> s;
    const auto n = nums.size();
    for (int i = 0; i < n; ++i) {
      if (auto it = s.lower_bound(static_cast<long>(nums[i]) - valueDiff);
          it != s.end() and *it <= static_cast<long>(nums[i]) + valueDiff)
        return true;
      s.insert(nums[i]);
      if (i >= indexDiff) s.erase(nums[i - indexDiff]);
    }
    return false;
  }
};
