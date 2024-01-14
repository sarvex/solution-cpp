#include <functional>
#include <vector>

class Solution {
public:
  int findCircleNum(const std::vector<std::vector<int>>& isConnected) {
    const int n = isConnected.size();
    int result = 0;
    std::vector seen(n, false);
    const std::function<void(int)> search = [&](const int i) {
      seen[i] = true;
      for (int j = 0; j < n; ++j)if (not seen[j] and isConnected[i][j]) search(j);
    };

    for (int i = 0; i < n; ++i) {
      if (not seen[i]) {
        search(i);
        ++result;
      }
    }
    return result;
  }
};
