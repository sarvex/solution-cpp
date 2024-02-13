#include <string>
#include <vector>

class Solution {
public:
  int firstUniqChar(const std::string& s) {
    std::vector cnt(26, 0);
    for (auto& c: s) ++cnt[c - 'a'];
    const auto n = s.size();
    for (int i = 0; i < n; ++i) if (cnt[s[i] - 'a'] == 1) return i;
    return -1;
  }
};
