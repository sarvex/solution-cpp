#include <string>
#include <vector>

class Solution {
public:
  int numDistinct(const std::string& s, const std::string& t) {
    const int n = t.size();
    std::vector result(n + 1, 0ULL);
    result[0] = 1;
    for (auto& ch: s) for (int j = n; j; --j) if (ch == t[j - 1]) result[j] += result[j - 1];
    return static_cast<int>(result[n]);
  }
};
