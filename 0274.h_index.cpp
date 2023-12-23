#include <algorithm>
#include <vector>

class Solution {
public:
  int hIndex(std::vector<int>& citations) {
    const int n = citations.size();
    std::vector count(n + 1, 0);
    for (const auto& citation: citations) { ++count[std::min(citation, n)]; }
    for (int h = n, s = 0;; --h) {
      s += count[h];
      if (s >= h) return h;
    }
  }
};
