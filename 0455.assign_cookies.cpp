#include <algorithm>
#include <vector>

class Solution {
public:
  int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    const int m = g.size(), n = s.size();
    for (int i = 0, j = 0; i < m; ++i) {
      while (j < n and s[j] < g[i]) { ++j; }
      if (j++ >= n) { return i; }
    }
    return m;
  }
};
