#include <vector>

class Solution {
public:
  int singleNumber(const std::vector<int>& nums) {
    int ans = 0;
    for (auto& num: nums) ans ^= num;
    return ans;
  }
};
