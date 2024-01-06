#include <numeric>
#include <vector>

class Solution {
public:
  int maximumsSplicedArray(const std::vector<int>& nums1, const std::vector<int>& nums2) {
    const auto find = [](const std::vector<int>& n1, const std::vector<int>& n2) {
      const int n = n1.size();
      int t = n1[0] - n2[0];
      int mx = t;
      for (int i = 1; i < n; ++i) {
        const int v = n1[i] - n2[i];
        if (t > 0) t += v;
        else t = v;
        mx = std::max(mx, t);
      }
      return mx;
    };

    return std::max(
        std::reduce(nums2.begin(), nums2.end()) + find(nums1, nums2),
        std::reduce(nums1.begin(), nums1.end()) + find(nums2, nums1));
  }
};
