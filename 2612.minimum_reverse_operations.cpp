#include <algorithm>
#include <queue>
#include <set>
#include <vector>

class Solution {
public:
  std::vector<int> minReverseOperationsFast(int n, int p, std::vector<int>& banned, int k) {
    std::vector graph(n, 0);
    std::vector visited{ p };

    for (int i = banned.size(); i; --i) graph[banned[i - 1]] = -1;

    if (not graph[p]) {
      int distance = 0;
      int size = visited.size();
      for (int left = n, right = 0,m = size, i = 0; i < size; ++i) {
        const int seen = visited[i];
        graph[seen] = distance;
        left = std::min(left, k < seen ? 1 - (k - seen) : (k - seen) - 1);
        right = std::max(right, k + seen > n ? (n << 1) - (seen + k) + 1 : (seen + k));
        if (--m < 1) {
          for (int j = std::max(left & 1, left); j < right; j += 2) if (not graph[j]) visited.emplace_back(j);
          left = visited.size();
          m = left - size;
          size = left;
          ++distance;
          left = n;
          right = 0;
        }
      }
    }
    std::replace_if(graph.begin(), graph.end(), [](const int x) { return not x; }, -1);
    graph[p] = 0;
    return graph;
  }

  std::vector<int> minReverseOperations(const int n, const int p, const std::vector<int>& banned, const int k) {
    std::vector result(n, -1);
    result[p] = 0;
    std::vector ts(2, std::set<int>());
    for (int i = 0; i < n; ++i) ts[i % 2].insert(i);
    ts[p % 2].erase(p);
    for (int i: banned) { ts[i % 2].erase(i); }
    ts[0].insert(n);
    ts[1].insert(n);
    std::queue<int> q{ { p } };
    while (! q.empty()) {
      const int i = q.front();
      q.pop();
      const int mi = std::max(i - k + 1, k - i - 1), mx = std::min(i + k - 1, n * 2 - k - i - 1);
      auto& s = ts[mi % 2];
      auto it = s.lower_bound(mi);
      while (*it <= mx) {
        int j = *it;
        result[j] = result[i] + 1;
        q.push(j);
        it = s.erase(it);
      }
    }
    return result;
  }
};
