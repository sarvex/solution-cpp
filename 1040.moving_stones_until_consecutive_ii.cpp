#include <algorithm>
#include <vector>

class Solution {
public:
  std::vector<int> numMovesStonesII(std::vector<int>& stones) {
    sort(stones.begin(), stones.end());
    const int n = static_cast<int>(stones.size());
    int mi = n;
    int mx = std::max(stones[n - 1] - stones[1] + 1, stones[n - 2] - stones[0] + 1) - (n - 1);
    for (int i = 0, j = 0; j < n; ++j) {
      while (stones[j] - stones[i] + 1 > n) { ++i; }
      if (j - i + 1 == n - 1 and stones[j] - stones[i] == n - 2) { mi = min(mi, 2); } else {
        mi = std::min(mi, n - (j - i + 1));
      }
    }
    return { mi, mx };
  }
};
