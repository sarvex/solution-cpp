#include <vector>

class Solution {
public:
  int findDuplicateFast(const vector<int>& nums) {
    int slow = nums[nums[0]];
    int fast = nums[nums[nums[0]]];

    while (slow != fast) {
      slow = nums[slow];
      fast = nums[nums[fast]];
    }

    slow = nums[0];
    while (slow != fast) {
      slow = nums[slow];
      fast = nums[fast];
    }

    return fast;
  }

  int findDuplicate(const std::vector<int>& nums) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
      const int mid = (l + r) >> 1;
      int cnt = 0;
      for (const int& v: nums) { cnt += v <= mid; }
      if (cnt > mid) { r = mid; } else { l = mid + 1; }
    }
    return l;
  }
};
