#include <vector>

class Solution {
public:
  int minSwap(std::vector<int>& nums1, std::vector<int>& nums2) {
    int a = 0, b = 1;
    const auto n = nums1.size();
    for (int i = 1; i < n; ++i) {
      const int x = a, y = b;
      if (nums1[i - 1] >= nums1[i] or nums2[i - 1] >= nums2[i]) {
        a = y, b = x + 1;
      } else {
        b = y + 1;
        if (nums1[i - 1] < nums2[i] and nums2[i - 1] < nums1[i]) {
          a = std::min(a, y);
          b = std::min(b, x + 1);
        }
      }
    }
    return std::min(a, b);
  }
};
