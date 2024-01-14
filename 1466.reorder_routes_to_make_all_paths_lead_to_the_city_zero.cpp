#include <functional>
#include <unordered_map>
#include <vector>

class Solution {
public:
  int minReorder(const int n, const std::vector<std::vector<int>>& connections) {
    std::unordered_map<int, std::vector<std::pair<int, bool>>> route;
    for (auto& connection: connections) {
      const int fst = connection[0], snd = connection[1];
      route[fst].emplace_back(snd, true);
      route[snd].emplace_back(fst, false);
    }
    std::vector<bool> seen(n);
    const std::function<int(int)> search = [&](int city) {
      seen[city] = true;
      int result = 0;
      for (const auto& p: route[city]) {
        if (const auto& [elem, exist] = p; not seen[elem]) {
          if (exist) ++result;
          result += search(elem);
        }
      }
      return result;
    };
    return search(0);
  }
};
