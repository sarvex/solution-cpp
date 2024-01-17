#include <vector>

class Solution {
public:
  int longestCycleFast(std::vector<int>& edges) {
    const auto n = edges.size();
    std::vector seen(n, -1);
    int result = -1, tm = 0;
    for (int i = 0; i < n; i++) {
      if (seen[i] != -1) continue;
      int cur = i;
      while (cur != -1 && seen[cur] == -1) {
        seen[cur] = tm++;
        int nxt = edges[cur];
        if (nxt != -1 && seen[nxt] != -1 && seen[nxt] >= seen[i]) result = std::max(result, seen[cur] - seen[nxt] + 1);
        cur = nxt;
      }
    }
    return result;
  }

  auto longestCycle(const std::vector<int>& edges) {
    const auto n = edges.size();
    std::vector seen(n, false);
    int result = -1;
    for (int i = 0; i < n; ++i) {
      if (seen[i]) continue;
      int j = i;
      std::vector<int> cycle;
      for (; j != -1 and ! seen[j]; j = edges[j]) {
        seen[j] = true;
        cycle.push_back(j);
      }
      if (j == -1) continue;
      for (int k = 0; k < cycle.size(); ++k)
        if (cycle[k] == j) {
          result = std::max(result, static_cast<int>(cycle.size()) - k);
          break;
        }
    }
    return result;
  }
};
