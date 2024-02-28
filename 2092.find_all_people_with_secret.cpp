#include <algorithm>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
  auto findAllPeople(int n, std::vector<std::vector<int>>& meetings, int firstPerson) {
    std::vector seen(n, false);
    seen[0] = seen[firstPerson] = true;
    std::ranges::sort(meetings, [&](const auto& x, const auto& y) { return x[2] < y[2]; });
    for (int i = 0, m = meetings.size(); i < m;) {
      int j = i;
      for (; j + 1 < m and meetings[j + 1][2] == meetings[i][2]; ++j)
        ;
      std::unordered_map<int, std::vector<int>> g;
      std::unordered_set<int> s;
      for (int k = i; k <= j; ++k) {
        int x = meetings[k][0], y = meetings[k][1];
        g[x].push_back(y);
        g[y].push_back(x);
        s.insert(x);
        s.insert(y);
      }
      std::queue<int> q;
      for (int u: s)
        if (seen[u]) q.push(u);
      while (! q.empty()) {
        int u = q.front();
        q.pop();
        for (int v: g[u]) {
          if (! seen[v]) {
            seen[v] = true;
            q.push(v);
          }
        }
      }
      i = j + 1;
    }
    std::vector<int> result;
    for (int i = 0; i < n; ++i)
      if (seen[i]) result.push_back(i);
    return result;
  }
};
