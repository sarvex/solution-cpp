#include <cstdint>
#include <vector>
#include <unordered_map>

using std::unordered_map;
using std::vector;

class Solution {
public:
  int countPairs(const vector<vector<int>>& coordinates, const int k) {
    unordered_map<uint64_t, int> cnt;
    auto f = [](const int x, const int y) { return x * 1000000L + y; };

    int result = 0;
    for (const auto& coordinate: coordinates) {
      const int x2 = coordinate[0], y2 = coordinate[1];
      for (int a = 0; a <= k; ++a)
        result += cnt[f(a ^ x2, (k - a) ^ y2)];
      ++cnt[f(x2, y2)];
    }
    return result;
  }
};
