#include <algorithm>
#include <vector>

using std::vector;

class Solution {
public:
  auto removeElement(vector<int> &nums, const int val) {
    nums.erase(remove(nums.begin(), nums.end(), val), nums.end());
    return nums.size();
  }
};
