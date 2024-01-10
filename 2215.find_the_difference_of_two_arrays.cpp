#include <algorithm>
#include <unordered_set>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> findDifferenceFast(std::vector<int>& nums1, std::vector<int>& nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    nums1.erase(unique(nums1.begin(), nums1.end()), nums1.end());
    nums2.erase(unique(nums2.begin(), nums2.end()), nums2.end());
    std::vector<std::vector<int>> result(2);
    set_difference(nums1.cbegin(), nums1.cend(), nums2.cbegin(), nums2.cend(), inserter(result[0], result[0].begin()));
    set_difference(nums2.cbegin(), nums2.cend(), nums1.cbegin(), nums1.cend(), inserter(result[1], result[1].begin()));
    return result;
  }

  std::vector<std::vector<int>> findDifference(std::vector<int>& nums1, std::vector<int>& nums2) {
    const std::unordered_set s1(nums1.begin(), nums1.end());
    const std::unordered_set s2(nums2.begin(), nums2.end());
    std::vector<std::vector<int>> result(2);
    for (int v: s1)
      if (! s2.contains(v))
        result[0].push_back(v);
    for (int v: s2)
      if (! s1.contains(v))
        result[1].push_back(v);
    return result;
  }
};
