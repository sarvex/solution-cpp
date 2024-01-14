#include <functional>
#include <limits>
#include <queue>

class Solution {
public:
  int minCost(const int maxTime, const std::vector<std::vector<int>>& edges, const std::vector<int>& passingFees) {
    constexpr auto inf = std::numeric_limits<int>::max();
    const auto n = static_cast<int>(passingFees.size());
    std::vector<std::pair<int, int>> adj[n];

    for (auto& edge: edges) {
      adj[edge[0]].emplace_back(edge[1], edge[2]);
      adj[edge[1]].emplace_back(edge[0], edge[2]);
    }

    std::priority_queue<std::pair<int, std::pair<int, int>>, std::vector<std::pair<int, std::pair<int, int>>>,
                        std::greater<>> p;
    std::vector cost(n, inf);
    std::vector time(n, inf);

    cost[0] = passingFees[0];
    time[0] = 0;

    p.push({ passingFees[0], { 0, 0 } });

    while (not p.empty()) {
      const auto [p_cost, p_time_node] = p.top();
      const auto [p_time, p_node] = p_time_node;
      p.pop();

      if (p_node == n - 1) return p_cost;

      for (const auto [n_node, n_time]: adj[p_node]) {
        if (p_time + n_time <= maxTime
            and (p_cost + passingFees[n_node] < cost[n_node] or p_time + n_time < time[n_node])) {
          time[n_node] = p_time + n_time;
          cost[n_node] = p_cost + passingFees[n_node];
          p.push({ cost[n_node], { time[n_node], n_node } });
        }
      }
    }
    return -1;
  }
};
