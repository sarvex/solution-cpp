#include <limits>
#include <vector>

class Solution {
public:
  int thirdMax(std::vector<int>& nums) {
    int m1 = std::numeric_limits<int>::min(), m2 = std::numeric_limits<int>::min(), m3 = std::numeric_limits<int>::min();
    for (const int num: nums) {
      if (num == m1 or num == m2 or num == m3) continue;
      if (num > m1) {
        m3 = m2;
        m2 = m1;
        m1 = num;
      } else if (num > m2) {
        m3 = m2;
        m2 = num;
      } else if (num > m3) { m3 = num; }
    }
    return m3 != std::numeric_limits<int>::min() ? m3 : m1;
  }
};
