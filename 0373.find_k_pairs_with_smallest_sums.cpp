#include <queue>
#include <vector>

class Solution {
public:
  auto kSmallestPairs(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
    const auto cmp = [&nums1, &nums2](const std::pair<int, int>& a, const std::pair<int, int>& b) {
      return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
    };

    const int m = nums1.size(), n = nums2.size();
    std::vector<std::vector<int>> result;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> pq(cmp);
    for (int i = 0; i < std::min(k, m); i++)
      pq.emplace(i, 0);
    while (k-- and ! pq.empty()) {
      auto [x, y] = pq.top();
      pq.pop();
      result.push_back({ nums1[x], nums2[y] });
      if (y + 1 < n)
        pq.emplace(x, y + 1);
    }

    return result;
  }
};
