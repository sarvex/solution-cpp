#include <functional>
#include <numeric>
#include <unordered_map>
#include <vector>

class Solution {
public:
  bool possibleBipartition(const int n, const std::vector<std::vector<int>>& dislikes) {
    std::vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    std::unordered_map<int, std::vector<int>> g;
    for (auto& e: dislikes) {
      const int a = e[0] - 1, b = e[1] - 1;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    std::function<int(int)> find = [&](const int x) {
      if (p[x] != x) p[x] = find(p[x]);
      return p[x];
    };
    for (int i = 0; i < n; ++i) {
      for (const int j: g[i]) {
        if (find(i) == find(j)) return false;
        p[find(j)] = find(g[i][0]);
      }
    }
    return true;
  }
};
