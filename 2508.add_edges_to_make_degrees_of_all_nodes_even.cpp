#include <vector>
#include<unordered_set>

using std::unordered_set;
using std::vector;

class Solution {
public:
  auto isPossible(const int n, const vector<vector<int>>& edges) {
    vector<unordered_set<int>> graph(n + 1);
    for (auto& edge: edges) {
      int a = edge[0], b = edge[1];
      graph[a].insert(b);
      graph[b].insert(a);
    }

    vector<int> result;
    for (int i = 1; i <= n; ++i) { if (graph[i].size() % 2) { result.emplace_back(i); } }
    if (result.empty()) { return true; }
    if (result.size() == 2) {
      const int a = result[0], b = result[1];
      if (! graph[a].contains(b)) return true;
      for (int c = 1; c <= n; ++c) {
        if (a != b and b != c and not graph[a].contains(c) and not graph[c].contains(b)) { return true; }
      }
      return false;
    }
    if (result.size() == 4) {
      const int a = result[0], b = result[1], c = result[2], d = result[3];
      if (not graph[a].contains(b) and not graph[c].contains(d)) return true;
      if (not graph[a].contains(c) and not graph[b].contains(d)) return true;
      if (not graph[a].contains(d) and not graph[b].contains(c)) return true;
      return false;
    }
    return false;
  }
};
