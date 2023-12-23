#include <string>

class Solution {
public:
  auto isSubsequence(const std::string* s, const std::string& t) {
    const int m = s.size(), n = t.size();
    if (m > n) return false;
    int i = 0;
    for (int j = 0; i < m and j < n; ++j) { if (s[i] == t[j]) { ++i; } }
    return i == m;
  }
};
