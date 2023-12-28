#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
  auto minDistance(const std::string& word1, const std::string& word2) {
    const int m = word1.size(), n = word2.size();
    std::vector result(m + 1, std::vector(n + 1, 0));
    for (int j = 0; j <= n; ++j) result[0][j] = j;
    for (int i = 1; i <= m; ++i) {
      result[i][0] = i;
      for (int j = 1; j <= n; ++j) {
        if (word1[i - 1] == word2[j - 1]) result[i][j] = result[i - 1][j - 1];
        else result[i][j] = std::min({ result[i - 1][j], result[i][j - 1], result[i - 1][j - 1] }) + 1;
      }
    }
    return result[m][n];
  }
};
