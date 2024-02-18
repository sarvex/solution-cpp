#include <vector>
class Solution {
public:
  auto rearrangeArray(const std::vector<int>& nums) {
    std::vector result(nums.size(), 0);
    int i = 0, j = 1;
    for (auto& num: nums) {
      if (num > 0) {
        result[i] = num;
        i += 2;
      } else {
        result[j] = num;
        j += 2;
      }
    }
    return result;
  }
};
