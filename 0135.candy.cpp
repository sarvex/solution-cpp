#include <algorithm>
#include <vector>

class Solution {
public:
  auto candy(std::vector<int>& ratings) {
    const int n = ratings.size();
    std::vector left(n, 1);
    std::vector right(n, 1);
    for (int i = 1; i < n; ++i) { if (ratings[i] > ratings[i - 1]) { left[i] = left[i - 1] + 1; } }
    for (int i = n - 2; ~i; --i) { if (ratings[i] > ratings[i + 1]) { right[i] = right[i + 1] + 1; } }
    int ans = 0;
    for (int i = 0; i < n; ++i) { ans += std::max(left[i], right[i]); }
    return ans;
  }
};
