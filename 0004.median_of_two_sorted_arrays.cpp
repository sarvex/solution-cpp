#include <algorithm>
#include <functional>
#include <limits>
#include <vector>

class Solution {
public:
  auto findMedianSortedArrays(const std::vector<int> &nums1,
                              const std::vector<int> &nums2) {
    const auto m = nums1.size();
    const auto n = nums2.size();

    std::function<double(int, int, int)> search = [&](const int i, const int j,
                                                      const int k) -> double {
      if (i >= m)
        return nums2[j + k - 1];
      if (j >= n)
        return nums1[i + k - 1];
      if (k == 1)
        return std::min(nums1[i], nums2[j]);

      const int p = k / 2;
      const int x =
          i + p - 1 < m ? nums1[i + p - 1] : std::numeric_limits<int>::max();
      const int y =
          j + p - 1 < n ? nums2[j + p - 1] : std::numeric_limits<int>::max();

      return x < y ? search(i + p, j, k - p) : search(i, j + p, k - p);
    };

    return ((m + n) % 2) ? search(0, 0, (m + n + 1) / 2)
                         : (search(0, 0, (m + n + 1) / 2) +
                            search(0, 0, (m + n + 2) / 2)) /
                               2.0;
  }
};
