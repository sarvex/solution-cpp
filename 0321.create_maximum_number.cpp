#include <functional>
#include <vector>

class Solution {
public:
  auto maxNumber(const std::vector<int>& nums1, const std::vector<int>& nums2, int k) {
    const auto table = [](const std::vector<int>& nums, const int k) {
      const auto n = static_cast<int>(nums.size());
      std::vector<int> stk(k);
      int top = -1;
      int remain = n - k;
      for (const int num: nums) {
        while (top >= 0 and stk[top] < num and remain > 0) {
          --top;
          --remain;
        }
        if (top + 1 < k) { stk[++top] = num; } else { --remain; }
      }
      return stk;
    };

    const std::function<bool(const std::vector<int>&, const std::vector<int>&, int, int)>
        compare = [&](const std::vector<int>& nums1, const std::vector<int>& nums2, const int i, const int j) -> bool {
          if (i >= nums1.size()) return false;
          if (j >= nums2.size()) return true;
          if (nums1[i] < nums2[j]) return false;
          if (nums1[i] > nums2[j]) return true;
          return compare(nums1, nums2, i + 1, j + 1);
        };

    const auto merge = [&](const std::vector<int>& nums1, const std::vector<int>& nums2) {
      const auto m = nums1.size(), n = nums2.size();
      int i = 0, j = 0;
      std::vector result(m + n, 0);
      for (int k = 0; k < m + n; ++k) {
        if (compare(nums1, nums2, i, j)) { result[k] = nums1[i++]; } else { result[k] = nums2[j++]; }
      }
      return result;
    };

    const auto m = static_cast<int>(nums1.size()), n = static_cast<int>(nums2.size());
    const int l = std::max(0, k - n), r = std::min(k, m);
    std::vector result(k, 0);
    for (int x = l; x <= r; ++x) {
      std::vector<int> arr1 = table(nums1, x);
      std::vector<int> arr2 = table(nums2, k - x);
      if (std::vector<int> arr = merge(arr1, arr2); result < arr) result = std::move(arr);
    }
    return result;
  }
};
