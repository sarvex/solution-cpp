#include <string>
#include <vector>

class Solution {
public:
  auto isInterleave(std::string s1, std::string s2, std::string s3) {
    const int m = s1.size(), n = s2.size();
    if (m + n != s3.size()) {
      return false;
    }
    std::vector<bool> result(n + 1);
    result[0] = true;
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        const int k = i + j - 1;
        if (i) {
          result[j] = s1[i - 1] == s3[k] and result[j];
        }
        if (j) {
          result[j] = (s2[j - 1] == s3[k] and result[j - 1]) or result[j];
        }
      }
    }
    return result[n];
  }
};
