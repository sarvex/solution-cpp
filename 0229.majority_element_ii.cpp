#include <algorithm>
#include <vector>

using std::ranges::count;
using std::vector;

class Solution {
public:
  auto majorityElement(vector<int>& nums) {
    int n1 = 0, n2 = 0;
    int m1 = 0, m2 = 1;
    for (const int m: nums) {
      if (m == m1) ++n1;
      else if (m == m2) ++n2;
      else if (n1 == 0) {
        m1 = m;
        ++n1;
      } else if (n2 == 0) {
        m2 = m;
        ++n2;
      } else {
        --n1;
        --n2;
      }
    }
    vector<int> result;
    if (count(nums, m1) > nums.size() / 3) result.push_back(m1);
    if (count(nums, m2) > nums.size() / 3) result.push_back(m2);
    return result;
  }
};
