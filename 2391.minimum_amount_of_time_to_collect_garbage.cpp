#include <numeric>
#include <string>
#include <vector>

class Solution {
public:
  auto garbageCollection(const std::vector<std::string>& garbage, const std::vector<int>& travel) {
    const auto n = garbage.size(), m = travel.size();
    std::vector last(26, 0);
    int result = 0;
    for (int i = 0; i < n; ++i) {
      result += garbage[i].size();
      for (auto& c: garbage[i]) { last[c - 'A'] = i; }
    }
    std::vector s(m + 1, 0);
    for (int i = 1; i <= m; ++i) { s[i] = s[i - 1] + travel[i - 1]; }
    for (const int i: last) { result += s[i]; }
    return result;
  }
};
