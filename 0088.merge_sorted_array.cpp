#include <vector>

using std::vector;

class Solution {
public:
  auto merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    vector<int> result;
    int i = 0, j = 0;

    while (i < m and j < n)
      result.emplace_back(nums1[i] <= nums2[j] ? nums1[i++] : nums2[j++]);

    while (i < m)
      result.emplace_back(nums1[i++]);
    while (j < n)
      result.emplace_back(nums2[j++]);

    nums1 = result;
  }
};
