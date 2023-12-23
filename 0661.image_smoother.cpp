#include <vector>

class Solution {
public:
  auto imageSmoother(std::vector<std::vector<int>>& img) {
    const auto m = img.size(), n = img[0].size();
    std::vector result(m, std::vector<int>(n));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        int s = 0, cnt = 0;
        for (int x = i - 1; x <= i + 1; ++x) {
          for (int y = j - 1; y <= j + 1; ++y) {
            if (x >= 0 and x < m and y >= 0 and y < n) {
              ++cnt;
              s += img[x][y];
            }
          }
        }
        result[i][j] = s / cnt;
      }
    }
    return result;
  }
};
