#include <unordered_set>
#include <vector>

class Solution {
public:
  int robotSim(const std::vector<int>& commands, const std::vector<std::vector<int>>& obstacles) {
    const std::vector dirs = { 0, 1, 0, -1, 0 };
    auto f = [](const int x, const int y) { return x * 60010 + y; };
    std::unordered_set<int> set;
    for (auto& e: obstacles) set.insert(f(e[0], e[1]));

    int result = 0, k = 0, x = 0, y = 0;
    for (auto& command: commands) {
      switch (command) {
        case -2: k = (k + 3) % 4; break;
        case -1: k = (k + 1) % 4; break;
        default: for (int i = 0; i < command; ++i) {
            if (not set.contains(f(x + dirs[k], y + dirs[k + 1]))) {
              x += dirs[k];
              y += dirs[k + 1];
              result = std::max(x * x + y * y, result);
            }
          }
      }
    }
    return result;
  }
};
