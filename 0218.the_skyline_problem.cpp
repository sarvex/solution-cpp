#include <map>
#include <set>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> getSkyline(const std::vector<std::vector<int>>& buildings) {
    std::set<int> position;
    std::map<int, int> m;
    for (auto& building: buildings) {
      position.insert(building[0]);
      position.insert(building[1]);
    }

    int i = 0;
    for (int pos: position) m.insert(std::pair(pos, i++));

    std::vector highs(m.size(), 0);
    for (auto v: buildings) {
      const int b = m[v[0]], e = m[v[1]];
      for (int i = b; i < e; ++i) highs[i] = std::max(highs[i], v[2]);
    }

    std::vector<std::vector<int>> result;
    std::vector mm(position.begin(), position.end());
    for (int i = 0; i < highs.size(); ++i) {
      if (highs[i] != highs[i + 1]) result.emplace_back(mm[i], highs[i]);
      else {
        const int start = i;
        result.emplace_back(mm[start], highs[i]);
        while (highs[i] == highs[i + 1]) ++i;
      }
    }
    return result;
  }
};
