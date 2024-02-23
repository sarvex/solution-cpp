#include <queue>
#include <unordered_map>
#include <vector>

class Solution {
public:
  auto findCheapestPrice(const int n, std::vector<std::vector<int>>& flights, int src, const int dst, const int k) {
    std::vector distances(n + 1, std::numeric_limits<int>::max());
    std::unordered_map<int, std::vector<std::pair<int, int>>> adj;
    for (auto& flight: flights)
      adj[flight[0]].emplace_back(flight[1], flight[2]);
    std::queue<std::pair<int, int>> q;
    q.emplace(src, 0);
    distances[src] = 0;
    for (int i = k; not q.empty() and i >= 0; --i) {
      int size = static_cast<int>(q.size());
      while (size--) {
        auto [node, distance] = q.front();
        q.pop();
        for (auto [adjacent, d]: adj[node])
        {
          if (d + distance < distances[adjacent]) {
            distances[adjacent] = d + distance;
            q.emplace(adjacent, distances[adjacent]);
          }
        }
      }
    }
    if (distances[dst] >= std::numeric_limits<int>::max()) return -1;
    return distances[dst];
  }

  int findCheapestPrice(
      const int n, const std::vector<std::vector<int>>& flights, const int src, const int dst, const int k) {
    constexpr int inf = 0x3f3f3f3f;
    std::vector dist(n, inf);
    std::vector<int> backup;
    dist[src] = 0;
    for (int i = 0; i < k + 1; ++i) {
      backup = dist;
      for (auto& e: flights) { dist[e[1]] = std::min(dist[e[1]], backup[e[0]] + e[2]); }
    }
    return dist[dst] == inf ? -1 : dist[dst];
  }
};
