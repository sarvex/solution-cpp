#include <vector>

using std::vector;

class Solution {
public:
  auto removeDuplicates(vector<int> &nums) {
    int k = 0;
    for (int x : nums) {
      if (k < 2 or x != nums[k - 2]) {
        nums[k++] = x;
      }
    }
    return k;
  }
};
