#include <vector>

class Solution {
public:
  int minimumTotal(std::vector<std::vector<int>>& triangle) {
    const int n = triangle.size();
    std::vector<int> result(n + 1);
    for (int i = n - 1; i >= 0; --i)
      for (int j = 0; j <= i; ++j)
        result[j] = std::min(result[j], result[j + 1]) + triangle[i][j];
    return result[0];
  }
};
