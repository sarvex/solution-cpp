#include <vector>

class Solution {
public:
  int findJudge(const int n, const std::vector<std::vector<int>>& trust) {
    std::vector cnt1(n + 1, 0);
    std::vector cnt2(n + 1, 0);
    for (auto& t: trust) {
      ++cnt1[t[0]];
      ++cnt2[t[1]];
    }
    for (int i = 1; i <= n; ++i)
      if (cnt1[i] == 0 and cnt2[i] == n - 1) return i;

    return -1;
  }
};
