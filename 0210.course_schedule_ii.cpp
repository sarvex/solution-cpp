#include <queue>
#include <vector>

class Solution {
public:
  std::vector<int> findOrder(const int numCourses, const std::vector<std::vector<int>>& prerequisites) {
    std::vector<std::vector<int>> g(numCourses);
    std::vector<int> indeg(numCourses);
    for (auto& p: prerequisites) {
      const int a = p[0], b = p[1];
      g[b].push_back(a);
      ++indeg[a];
    }
    std::queue<int> q;
    for (int i = 0; i < numCourses; ++i) if (indeg[i] == 0) q.push(i);
    std::vector<int> result;
    while (not q.empty()) {
      int i = q.front();
      q.pop();
      result.push_back(i);
      for (int j: g[i]) if (--indeg[j] == 0) q.push(j);
    }
    return result.size() == numCourses ? result : std::vector<int>();
  }
};
