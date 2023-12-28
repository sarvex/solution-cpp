#include <string>
#include <vector>

class Solution {
public:
  int minCost(const std::string& colors, const std::vector<int>& neededTime) {
    int result = 0;
    const int n = colors.size();
    for (int i = 0, j = 0; i < n; i = j) {
      j = i;
      int s = 0, mx = 0;
      while (j < n and colors[j] == colors[i]) {
        s += neededTime[j];
        mx = std::max(mx, neededTime[j]);
        ++j;
      }
      if (j - i > 1) { result += s - mx; }
    }
    return result;
  }
};
