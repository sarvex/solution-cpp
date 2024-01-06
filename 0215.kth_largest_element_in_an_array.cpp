#include <vector>

class Solution {
public:
  int findKthLargest(std::vector<int>& nums, int k) {
    const int n = nums.size();
    return quickSort(nums, 0, n - 1, n - k);
  }

  int quickSort(std::vector<int>& nums, int left, int right, int k) {
    if (left == right) return nums[left];
    int i = left - 1, j = right + 1;
    const int x = nums[left + right >> 1];
    while (i < j) {
      while (nums[++i] < x);
      while (nums[--j] > x);
      if (i < j) std::swap(nums[i], nums[j]);
    }
    return j < k ? quickSort(nums, j + 1, right, k) : quickSort(nums, left, j, k);
  }
};
