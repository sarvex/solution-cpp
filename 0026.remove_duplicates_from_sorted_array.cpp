#include <algorithm>
#include <vector>

class Solution {
public:
  auto removeDuplicates(std::vector<int>& nums) {
    nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
    return nums.size();
  }
};
