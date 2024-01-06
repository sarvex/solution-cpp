#include <vector>

class Solution {
public:
  int singleNumber(const std::vector<int>& nums) {
    int a = 0, b = 0;
    for (auto& num: nums) {
      const int aa = (~a & b & num) | (a & ~b & ~num);
      const int bb = ~a & (b ^ num);
      a = aa;
      b = bb;
    }
    return b;
  }
};
