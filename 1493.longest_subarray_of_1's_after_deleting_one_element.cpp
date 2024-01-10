#include <vector>

class Solution {
public:
  int longestSubarrayFast(const std::vector<int>& nums) {
    int left = 0, right = 0, deleted = 0;
    while (right < nums.size()) {
      if (nums[right] == 0)
        deleted++;
      if (deleted > 1) {
        if (nums[left] == 0) deleted--;
        left++;
      }
      right++;
    }
    return right - left - 1;
  }

  int longestSubarray(const std::vector<int>& nums) {
    const int n = nums.size();
    std::vector<int> left(n);
    std::vector<int> right(n);
    for (int i = 1; i < n; ++i) {
      if (nums[i - 1] == 1) left[i] = left[i - 1] + 1;
      if (nums[n - i] == 1) right[n - i] = right[n - i + 1] + 1;
    }
    int result = 0;
    for (int i = 0; i < n; ++i) { result = std::max(result, left[i] + right[i]); }
    return result;
  }
};
