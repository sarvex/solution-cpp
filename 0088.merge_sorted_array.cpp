#include <vector>

using std::vector;

class Solution {
public:
  void merge(vector<int>& nums1, const int m, const vector<int>& nums2, const int n) {
    for (int i = m - 1, j = n - 1, k = m + n - 1; ~j; --k) {
      nums1[k] = i >= 0 and nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
    }
  }
};
