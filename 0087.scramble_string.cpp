#include <functional>
#include <string>

class Solution {
public:
  auto isScramble(const std::string& s1, const std::string& s2) {
    const int n = s1.size();
    std::vector result(n, std::vector(n, std::vector(n + 1, -1)));
    const std::function<int(int, int, int)> search = [&](const int i, const int j, const int k) -> int {
      if (result[i][j][k] != -1) return result[i][j][k] == 1;
      if (k == 1) return s1[i] == s2[j];
      for (int h = 1; h < k; ++h) {
        if (search(i, j, h) and search(i + h, j + h, k - h)) return result[i][j][k] = true;
        if (search(i + h, j, k - h) and search(i, j + k - h, h)) return result[i][j][k] = true;
      }
      return result[i][j][k] = false;
    };
    return search(0, 0, n);
  }
};
