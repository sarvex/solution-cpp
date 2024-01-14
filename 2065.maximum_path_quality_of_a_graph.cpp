#include <functional>
#include <queue>
#include <vector>
#include <utility>

class Solution {
public:
  auto maximalPathQualityFast( const std::vector<int>& values, const std::vector<std::vector<int>>& edges, const int maxTime) {
    const int n = static_cast<int>(values.size());
    std::vector<std::unordered_map<int, int>> edge_map(n);
    for (auto& e: edges) {
      edge_map[e[0]].insert({ e[1], e[2] });
      edge_map[e[1]].insert({ e[0], e[2] });
    }

    std::vector seen(n, false);
    std::vector distance(n, 0x3f3f3f3f);
    distance[0] = 0;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
    pq.emplace(0, 0);
    while (not pq.empty()) {
      const int u = pq.top().second;
      pq.pop();
      if (seen[u]) continue;
      for (auto& [v, weight]: edge_map[u]) {
        if (distance[v] > distance[u] + weight) {
          distance[v] = distance[u] + weight;
          pq.emplace(distance[v], v);
        }
      }
    }

    int result = 0;
    std::fill(seen.begin(), seen.end(), false);
    seen[0] = true;
    std::function<void(int, int, int)> search = [&](const int node, int score, const int time) {
      if (time + distance[node] > maxTime)
        return;
      bool set_true = false;
      if (not seen[node]) {
        score += values[node];
        seen[node] = true;
        set_true = true;
      }
      if (time + distance[node] <= maxTime) result = std::max(result, score);
      for (auto& [fst, snd]: edge_map[node]) search(fst, score, time + snd);
      seen[node] = not set_true;
    };
    search(0, values[0], 0);
    return result;
  }

  auto maximalPathQuality(
      const std::vector<int>& values,
      const std::vector<std::vector<int>>& edges,
      const int maxTime) {
    const auto n = static_cast<int>(values.size());
    auto result = values[0];
    std::vector<std::vector<std::pair<int, int>>> graph(n);
    for (auto& edge: edges) {
      graph[edge[0]].emplace_back(edge[1], edge[2]);
      graph[edge[1]].emplace_back(edge[0], edge[2]);
    }

    std::vector visited(n, 0);
    std::function<void(int, int, int)> search = [&](const int node, int score, const int time) {
      if (time > maxTime) return;
      if (visited[node] == 0) score += values[node];
      visited[node]++;

      if (node == 0) result = std::max(result, score);
      for (auto [fst, snd]: graph[node]) search(fst, score, time + snd);
      visited[node]--;
    };
    search(0, 0, 0);
    return result;
  }
};
