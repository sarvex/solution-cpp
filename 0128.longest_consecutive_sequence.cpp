#include <unordered_set>
#include <vector>

class Solution {
public:
  int longestConsecutive(const std::vector<int>& nums) {
    const std::unordered_set set(nums.begin(), nums.end());
    int result = 0;
    for (auto& x: nums) {
      if (not set.contains(x - 1)) {
        int y = x + 1;
        while (set.contains(y)) { y++; }
        result = std::max(result, y - x);
      }
    }
    return result;
  }
};
