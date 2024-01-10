#include <vector>

class Solution {
public:
  std::vector<int> findErrorNums(const std::vector<int>& nums) {
    const int n = nums.size();
    int xs = 0;
    for (int i = 1; i <= n; ++i) { xs ^= i ^ nums[i - 1]; }
    const int lb = xs & -xs;
    int a = 0;
    for (int i = 1; i <= n; ++i) {
      if (i & lb) { a ^= i; }
      if (nums[i - 1] & lb) { a ^= nums[i - 1]; }
    }
    int b = xs ^ a;
    for (int i = 0; i < n; ++i) { if (nums[i] == a) { return { a, b }; } }
    return { b, a };
  }
};
