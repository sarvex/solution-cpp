#include <algorithm>
#include <vector>

class Solution {
public:
  int maxOperations(std::vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int result = 0;

    for (int i = 0, j = nums.size() - 1; i < j;) {
      if (nums[i] + nums[j] == k) {
        i++;
        j--;
        result++;
      } else if (nums[i] + nums[j] > k) { j--; } else { i++; }
    }
    return result;
  }
};
