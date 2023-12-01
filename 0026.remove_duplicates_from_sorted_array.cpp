#include <algorithm>
#include <vector>

class Solution {
public:
  static int removeDuplicates(std::vector<int>& nums) {
    nums.erase(std::ranges::unique(nums).begin(), nums.end());
    return nums.size();
  }
};
