#include <string>
#include <vector>

class Solution {
public:
  bool isIsomorphic(const std::string& s, const std::string& t) {
    if (s.size() != t.size()) return false;
    std::vector d1 (128, 0);
    std::vector d2 (128, 0);
    const int n = s.size();
    for (int i = 0; i < n; ++i) {
      const char a = s[i], b = t[i];
      if (d1[a] != d2[b]) return false;
      d1[a] = d2[b] = i + 1;
    }
    return true;
  }
};
