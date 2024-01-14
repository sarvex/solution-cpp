#include <cstdint>
#include <limits>
#include <queue>
#include <vector>

class Solution {
public:
  auto minimumWeight(
      const int n,
      const std::vector<std::vector<int>>& edges,
      const int src1,
      const int src2,
      const int dest) {
    std::vector<std::vector<std::pair<int, int>>> adj(n + 100);
    std::vector<std::vector<std::pair<int, int>>> rev(n + 100);

    for (auto x: edges) {
      adj[x[0]].emplace_back(x[2], x[1]);
      rev[x[1]].emplace_back(x[2], x[0]);
    }

    const auto dijkstra = [&](std::vector<std::vector<std::pair<int, int>>> graph, const int u) {
      std::vector result(n + 100, std::numeric_limits<int>::max());
      std::vector seen(n + 100, false);
      result[u] = 0;
      std::priority_queue<std::pair<int64_t, int>, std::vector<std::pair<int64_t, int>>, std::greater<>> pq;
      pq.emplace(0, u);
      while (not pq.empty()) {
        const std::pair<int64_t, int> top = pq.top();
        const int d = top.second;
        pq.pop();
        if (not seen[d]) {
          seen[d] = true;
          for (auto x: graph[d]) {
            int dk = x.second;
            const int64_t w = x.first;
            if (result[dk] > result[d] + w) {
              result[dk] = result[d] + w;
              pq.emplace(result[dk], dk);
            }
          }
        }
      }
      return result;
    };

    const std::vector<int64_t> dist_src1 = dijkstra(adj, src1);
    const std::vector<int64_t> dist_src2 = dijkstra(adj, src2);
    const std::vector<int64_t> dist_dest = dijkstra(rev, dest);
    constexpr auto inf = std::numeric_limits<int>::max();
    int64_t result = inf;
    for (int i = 0; i < n; i++) result = std::min(result, dist_src1[i] + dist_src2[i] + dist_dest[i]);
    return result == inf ? -1 : result;
  }
};
