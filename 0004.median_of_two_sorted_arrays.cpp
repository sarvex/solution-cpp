#include <functional>
#include <vector>

class Solution {
public:
  static double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2) {
    const int m = nums1.size();
    const int n = nums2.size();

    std::function<int(int, int, int)> f = [&](const int i, const int j,
                                              const int k) {
      if (i >= m) {
        return nums2[j + k - 1];
      }
      if (j >= n) {
        return nums1[i + k - 1];
      }
      if (k == 1) {
        return std::min(nums1[i], nums2[j]);
      }
      const int p = k / 2;
      const int x = i + p - 1 < m ? nums1[i + p - 1] : 1 << 30;
      const int y = j + p - 1 < n ? nums2[j + p - 1] : 1 << 30;
      return x < y ? f(i + p, j, k - p) : f(i, j + p, k - p);
    };

    const auto a = f(0, 0, (n + m + 1) / 2);
    const auto b = f(0, 0, (m + n + 2) / 2);
    return (a + b) / 2.0;
  }
};
